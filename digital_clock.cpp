#include "raylib.h"
#include <ctime>
#include <cstdio>

Color bgColor = {8, 8, 8, 255};
Color segmentColor = {255, 48, 72, 255};
Color offSegmentColor = {35, 35, 35, 255};

const float initX = 100.0f;
const float initY = 100.0f;
const float fullSegmentW = 80.0f;
const float fullSegmentH = 130.0f;
//: prototype

void drawPair(float xPos, float yPos, int timer);
void drawColon(float xPos, float yPos); // expecting the yPos = initY
void drawCompleteSegments(float stX, float stY, int num);

void drawNine(float stX, float stY);
void drawEight(float stX, float stY);
void drawSeven(float stX, float stY);
void drawSix(float stX, float stY);
void drawFive(float stX, float stY);
void drawFour(float stX, float stY);
void drawThree(float stX, float stY);
void drawTwo(float stX, float stY);
void drawOne(float stX, float stY);
void drawZero(float stX, float stY);

Vector2 drawSegmentVr(float x, float y, Color color);
Vector2 drawSegmentHr(float x, float y, Color color);

int main()
{

  InitWindow(800, 450, "Digital Clock");
  SetTargetFPS(60);
  // float counter = 0 ;
  // int timer  = 0;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(bgColor);
    // float dt = GetFrameTime();
    // counter+=dt;
    // if(counter>=1.0f)
    //   {
    //     timer = ++timer%60;
    //     counter-=1.0f;
    //   }

    time_t now = time(nullptr);
    tm *currentTime = localtime(&now);
    int hour12 = (currentTime->tm_hour) % 12;
    if (hour12 == 0)
    {
      hour12 = 12;
    }

    int minute = currentTime->tm_min;
    int second = currentTime->tm_sec;

    drawPair(initX, initY, hour12);
    drawColon(initX + 2 * fullSegmentW, initY);

    drawPair(3 * initX, initY, minute);
    drawColon(3 * initX + 2 * fullSegmentW, initY);

    drawPair(5 * initX, initY, second);
    //: working
    // drawCompleteSegments(initX,initY+130.0f,timer);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

//: definition

void drawCompleteSegments(float stX, float stY, int num)
{
  switch (num)
  {
  case 0:
    drawZero(stX, stY);
    break;
  case 1:
    drawOne(stX, stY);
    break;
  case 2:
    drawTwo(stX, stY);
    break;
  case 3:
    drawThree(stX, stY);
    break;
  case 4:
    drawFour(stX, stY);
    break;
  case 5:
    drawFive(stX, stY);
    break;
  case 6:
    drawSix(stX, stY);
    break;
  case 7:
    drawSeven(stX, stY);
    break;
  case 8:
    drawEight(stX, stY);
    break;
  case 9:
    drawNine(stX, stY);
    break;

  default:
    break;
  }
}
void drawZero(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, offSegmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, segmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawOne(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, offSegmentColor);
  Vector2 b = drawSegmentVr(stX, stY, offSegmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, offSegmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, offSegmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawTwo(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, offSegmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, segmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, offSegmentColor);
}

void drawThree(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, offSegmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawFour(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, offSegmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, offSegmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawFive(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, offSegmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawSix(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, offSegmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, segmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawSeven(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, offSegmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, offSegmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawEight(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, segmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

void drawNine(float stX, float stY)
{

  Vector2 a = drawSegmentHr(stX, stY, segmentColor);
  Vector2 b = drawSegmentVr(stX, stY, segmentColor);
  Vector2 c = drawSegmentVr(a.x, a.y, segmentColor);

  Vector2 x = drawSegmentHr(b.x, b.y, segmentColor);

  Vector2 d = drawSegmentVr(b.x, b.y, offSegmentColor);
  Vector2 e = drawSegmentHr(d.x, d.y, segmentColor);
  Vector2 f = drawSegmentVr(c.x, c.y, segmentColor);
}

Vector2 drawSegmentVr(float x, float y, Color color)
{
  float trHeight = 10.0f;
  float trWidth = 20.0f;
  float rectHeight = 30.0f;
  float rectWidth = 20.0f;

  Vector2 a = {x, y};
  Vector2 b = {x + trWidth / 2, y + trHeight};
  Vector2 c = {x - trWidth / 2, y + trHeight};
  Vector2 d = {x - rectWidth / 2, y + trHeight + rectHeight};
  Vector2 e = {x + rectWidth / 2, y + trHeight + rectHeight};
  Vector2 f = {x, y + 2 * trHeight + rectHeight};
  Rectangle rec = {x - rectWidth / 2, y + trHeight, rectWidth, rectHeight};

  // drawing
  DrawTriangle(a, c, b, color);
  DrawRectangleRec(rec, color);
  DrawTriangle(d, f, e, color);
  return f;
}

Vector2 drawSegmentHr(float x, float y, Color color)
{
  float trWidth = 10.0f;
  float trHeight = 20.0f;
  float rectWidth = 30.0f;
  float rectHeight = 20.0f;

  Vector2 a = {x, y};
  Vector2 b = {x + trWidth, y - trHeight / 2};
  Vector2 c = {x + trWidth, y + trHeight / 2};
  Vector2 d = {x + trWidth + rectWidth, y - rectHeight / 2};
  Vector2 e = {x + trWidth + rectWidth, y + rectHeight / 2};
  Vector2 f = {x + 2 * trWidth + rectWidth, y};
  Rectangle rec = {x + trWidth, y - rectHeight / 2, rectWidth, rectHeight};

  // drawing
  DrawTriangle(a, c, b, color);
  DrawRectangleRec(rec, color);
  DrawTriangle(d, e, f, color);
  return f;
}

void drawColon(float xPos, float yPos)
{
  float segment = yPos + (fullSegmentH - 60.0f) / 4.0f;

  Rectangle rec1 = {xPos, segment, 15, 15};
  Rectangle rec2 = {xPos, segment + 50, 15, 15};

  DrawRectangleRec(rec1, segmentColor);
  DrawRectangleRec(rec2, segmentColor);
}

void drawPair(float xPos, float yPos, int timer)
{
  if (timer > 9)
  {
    drawCompleteSegments(xPos, yPos, int(timer / 10));
    drawCompleteSegments(xPos + fullSegmentW, yPos, timer % 10);

    return;
  }
  drawCompleteSegments(xPos, yPos, 0);
  drawCompleteSegments(xPos + fullSegmentW, yPos, timer);
}