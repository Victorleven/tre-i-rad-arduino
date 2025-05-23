#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

char squares[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int x_pos[9] = { 17, 60, 96, 17, 60, 96, 17, 60, 96 };
int y_pos[9] = { 16, 16, 16, 36, 36, 36, 58, 58, 58 };
int position = 4;
bool playing = true;
bool circle = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT_PULLUP);
  u8g.setFont(u8g_font_unifont);
}

void loop() {
  while (playing == true) {

    boardWrite();

    if (digitalRead(2) == HIGH) {
      if (position == 0) {
        position = 8;
      } else
        position -= 1;
    } else if (digitalRead(4) == HIGH) {
      if (position == 8) {
        position = 0;
      } else
        position += 1;
    }
    if (digitalRead(3) == HIGH) {
      if (circle == false) {
        if (squares[position] != 'O') {
          if (squares[position] != 'X') {
            circle = true;
          }
          squares[position] = 'X';
        }
      }
      if (circle == true) {
        if (squares[position] != 'X') {
          if (squares[position] != 'O') {
            circle = false;
          }
          squares[position] = 'O';
        }
      }
    }
    checkState();
  }
}

void boardWrite() {
  u8g.firstPage();

  do {
    u8g.drawFrame(0, 0, 128, 64);
    u8g.drawHLine(0, 21, 128);
    u8g.drawHLine(0, 42, 128);
    u8g.drawVLine(42, 0, 64);
    u8g.drawVLine(84, 0, 64);

    u8g.drawStr(x_pos[position], (y_pos[position]+1), "_");

    for (int i = 0; i < 9; i++) {
      if (squares[i] == 'X') {
        u8g.drawStr(x_pos[i], y_pos[i], "X");
      } else if (squares[i] == 'O') {
        u8g.drawStr(x_pos[i], y_pos[i], "O");
      } else {
        u8g.drawStr(x_pos[i], y_pos[i], " ");
      }
    }

    /*char buffer[2];
    buffer[0] = squares[0];
    buffer[1] = '\0';
    u8g.drawStr(18, 16, buffer);
    buffer[0] = squares[3];
    buffer[1] = '\0';
    u8g.drawStr(18, 16 + 21, buffer);
    buffer[0] = squares[6];
    buffer[1] = '\0';
    u8g.drawStr(18, 16 + 42, buffer);

    buffer[0] = squares[1];
    buffer[1] = '\0';
    u8g.drawStr(18 + 42, 16, buffer);
    buffer[0] = squares[4];
    buffer[1] = '\0';
    u8g.drawStr(18 + 42, 16 + 21, buffer);
    buffer[0] = squares[7];
    buffer[1] = '\0';
    u8g.drawStr(18 + 42, 16 + 42, buffer);

    buffer[0] = squares[2];
    buffer[1] = '\0';
    u8g.drawStr(18 + 84, 16, buffer);
    buffer[0] = squares[5];
    buffer[1] = '\0';
    u8g.drawStr(18 + 84, 16 + 21, buffer);
    buffer[0] = squares[8];
    buffer[1] = '\0';
    u8g.drawStr(18 + 84, 16 + 42, buffer);
*/
  } while (u8g.nextPage());
}

void checkState() {
  for (int i = 0; i < 2; i++) {
    for (int i = 0; i < 3; i++) {
      
  }
  }
}