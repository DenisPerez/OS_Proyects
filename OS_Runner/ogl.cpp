#include <iostream>
#include <GL/glew.h>

#include "ogl.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static GLuint load_texture(const char * texImagePath, int * width, int * height) {
  GLuint textureID = 0;
  int nrComponent;

  // Load image
  stbi_set_flip_vertically_on_load(true);
  unsigned char * texData = stbi_load(texImagePath, width, height, &nrComponent, 0);

  if(texData) {
    // Check how many color channels the image has
    GLenum format = GL_RGB;
    if (nrComponent == 1)
      format = GL_RED;
    else if(nrComponent == 3)
      format = GL_RGB;
    else if(nrComponent == 4)
      format = GL_RGBA;

    // Create a new OpenGL texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    //set parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Create the texture
    glTexImage2D(GL_TEXTURE_2D,0, format, *width, *height, 0, format, GL_UNSIGNED_BYTE, texData);

    // Release image data
    stbi_image_free(texData);

  } else {
    printf("failed to find texture: %s", texImagePath);
    stbi_image_free(texData);
  }

  return textureID;
}

namespace opengl
{
  //constants
  const float NCP = -10.0f;
  const float FCP =  10.0f;

  //globals
  const std::string sWindowTitle = "OS Runner"; // Name of the window
  unsigned int      iWidthWindow = 800;         // Width of the viewport
  unsigned int      iHeightWindow = 800;        // Height of the viewport
  GLuint            iTextureId;                 // OpenGL 2D texture id
  GLuint            iMapList;                   // Map display list
  int               iTexWidth;                  // Texture width
  int               iTexHeight;                 // Texture height

  void initialize(const data_t * data) {
    float s, t;

    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    reshape(800, 800);

    iTextureId = load_texture("Nh343-nextstep.png", &iTexWidth, &iTexHeight);

    // Generate a display list for the map
    iMapList = glGenLists(1);

    // Create the map display list
    glNewList(iMapList, GL_COMPILE);
    // Draw map tiles
    for (int i = 0; i < data->width; i++) {
      for (int j = 0; j < data->height; j++) {
        // Set the base texture coord for the current tile depending on it's type
        switch (data->map_layer[(i * data->width) + j]) {
        case WALL:
          s = (30.0f * 8) / iTexWidth; t = (30.0f * 6) / iTexHeight;
          break;
        case GRND:
          s = (30.0f * 9) / iTexWidth; t = (30.0f * 6) / iTexHeight;
          break;
        case DOOR:
          s = (30.0f * 4) / iTexWidth; t = (30.0f * 6) / iTexHeight;
          break;
        case EXIT:
          s = (30.0f * 21) / iTexWidth; t = (30.0f * 5) / iTexHeight;
          break;
        default:
          s = 0.0f; t = 0.0f;
        }

        // Save the global matrix transform
        glPushMatrix();
        glTranslatef((i + 1) * 32.0f, j * 32.0f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        // Draw each tile as an OpenGL quad
        glBegin(GL_QUADS);
        // Set the color of all vertices of the tile to white
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        // Send the vertices with texture coordinates
        glTexCoord2f(s, t);
        glVertex3f(0.0f, 0.0f, -3.0f);
        glTexCoord2f(s, t + (30.0f / iTexHeight));
        glVertex3f(0.0f, 32.0f, -3.0f);
        glTexCoord2f(s + (30.0f / iTexWidth), t + (30.0f / iTexHeight));
        glVertex3f(32.0f, 32.0f, -3.0f);
        glTexCoord2f(s + (30.0f / iTexWidth), t);
        glVertex3f(32.0f, 0.0f, -3.0f);
        glEnd();
        glPopMatrix();
      }
    }
    glEndList();
  }

  void display(const data_t * data)
  {
    float s, t, x, y;

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Clear the model-view matrix
    glLoadIdentity();

    // Give up if there is no map data
    if (data == NULL)
      return;

    // Enable the texture
    glBindTexture(GL_TEXTURE_2D, iTextureId);

    // Render the map
    glCallList(iMapList);
    /*
    // Draw items
    for (int i = 0; i < MAX_ITEMS; i++) {
      // Set the base texture coord for the current tile depending on it's type
      switch (data->items[i].type) {
      case TREASURE:
        s = (30.0f * 7) / iTexWidth; t = (30.0f * 13) / iTexHeight;
        break;
      case KEY:
        s = (30.0f * 3) / iTexWidth; t = (30.0f * 12) / iTexHeight;
        break;
      case NO_ITEM:
        continue;
        break;
      default:
        s = 0.0f; t = 0.0f;
      }

      x = data->items[i].x;
      y = data->items[i].y;

      // Save the global matrix transform
      glPushMatrix();
      glTranslatef((x + 1) * 32.0f, y * 32.0f, 0.0f);
      glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
      // Draw each item as an OpenGL quad
      glBegin(GL_QUADS);
      // Set the color of all vertices of the item to white
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
      // Send the vertices with texture coordinates
      glTexCoord2f(s, t);
      glVertex3f(0.0f, 0.0f, -2.0f);
      glTexCoord2f(s, t + (30.0f / iTexHeight));
      glVertex3f(0.0f, 32.0f, -2.0f);
      glTexCoord2f(s + (30.0f / iTexWidth), t + (30.0f / iTexHeight));
      glVertex3f(32.0f, 32.0f, -2.0f);
      glTexCoord2f(s + (30.0f / iTexWidth), t);
      glVertex3f(32.0f, 0.0f, -2.0f);
      glEnd();
      glPopMatrix();
    }
    */
    // Draw player character and NPC's
    for (int i = 0; i < MAX_CHARACTERS; i++) {
      // Set the base texture coord for the current tile depending on it's type
      switch (data->characters[i].type) {
      case PLAYER:
        s = (30.0f * 2) / iTexWidth; t = (30.0f * 18) / iTexHeight;
        break;
      case COMPUTER:
        s = (30.0f * 2) / iTexWidth; t = (30.0f * 21) / iTexHeight;
        break;
      case ENEMY:
        s = (30.0f * 0) / iTexWidth; t = (30.0f * 21) / iTexHeight;
        break;
      case NO_CHAR:
        continue;
        break;
      default:
        s = 0.0f; t = 0.0f;
      }

      x = data->characters[i].x;
      y = data->characters[i].y;

      // Save the global matrix transform
      glPushMatrix();
      glTranslatef((x + 1) * 32.0f, y * 32.0f, 0.0f);
      glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
      // Draw each item as an OpenGL quad
      glBegin(GL_QUADS);
      // Set the color of all vertices of the item to white
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
      // Send the vertices with texture coordinates
      glTexCoord2f(s, t);
      glVertex3f(0.0f, 0.0f, -1.0f);
      glTexCoord2f(s, t + (30.0f / iTexHeight));
      glVertex3f(0.0f, 32.0f, -1.0f);
      glTexCoord2f(s + (30.0f / iTexWidth), t + (30.0f / iTexHeight));
      glVertex3f(32.0f, 32.0f, -1.0f);
      glTexCoord2f(s + (30.0f / iTexWidth), t);
      glVertex3f(32.0f, 0.0f, -1.0f);
      glEnd();
      glPopMatrix();
    }
  }

  void reshape(int w, int h)
  {
    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, iWidthWindow, 0.0f, iHeightWindow, NCP, FCP);
    // Rotate the view 90 degrees
    glTranslatef(0.0f, iHeightWindow, 0.0f);
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    // Set the model view matrix
    glMatrixMode(GL_MODELVIEW);
  }
}
