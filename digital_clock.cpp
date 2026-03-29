#include "raylib.h"

typedef struct {
  Vector2 a;
  Vector2 b;
  Vector2 c;
} Triangle;

//: prototype
void drawSegment(float x, float y, Color color);

int main() {

  InitWindow(800, 450, "Digital Clock");
  SetTargetFPS(60);

  Triangle right = {
      .a = {270.0f, 212.5f},
      .b = {250.0f, 200.0f},
      .c = {250.0f, 225.0f},
  };

  Triangle left = {
      .a = {180.0f, 212.5f},
      .b = {200.0f, 225.0f},
      .c = {200.0f, 200.0f},
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    // DrawRectangle(200.0f, 200.0f, 50.0f, 25.0f, RED);
    // DrawTriangle(right.a, right.b, right.c, RED);
    // DrawTriangle(left.a, left.b, left.c, RED);
    drawSegment(100, 100, RED);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void drawSegment(float x, float y, Color color) {
  Vector2 a = {x, y};
  Vector2 b = {x + 10.0f, y - 10.0f};
  Vector2 c = {x + 10.0f, y + 10.0f};
  Vector2 d = {x + 40.0f, y - 10.0f};
  Vector2 e = {x + 40.0f, y + 10.0f};
  Vector2 f = {x + 50.0f, y};
  Rectangle rec = {b.x, b.y, 30, 20};


  DrawTriangle(a, c, b, color);
  DrawRectangleRec(rec, color);
  DrawTriangle(d, e, f, color);
}
