#include "manipulator.h"
#include "utility.h"

int numLinks = 5;
Point pos;
int err;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);

  Range r(PIdiv2, -PIdiv2);
  Link* links = new Link[numLinks];
  Angles startingPos(PIdiv2);
  Point destination(250, 300, 20);
  links[0] = Link(100, new TwistingJoint(r, 0));
  links[1] = Link(200, new RotationJoint(r, 0));
  links[2] = Link(150, new RotationJoint(r, 0));
  links[3] = Link(120, new RotationJoint(r, 0));
  links[4] = Link(120, new RotationJoint(r, 0));
  Manipulator manip(links, numLinks, startingPos);

  pos = manip.computePosition();
  err = pos.distanceTo(destination);
  //Serial.println("Point:");
  Serial.println(pos.x);
  Serial.println(pos.y);
  Serial.println(pos.z);
  Serial.println("Error: ");
  Serial.println(err);

  manip.reachPosition(destination);
  pos = manip.computePosition();
  //Serial.println("Point:");
  Serial.println(pos.x);
  Serial.println(pos.y);
  Serial.println(pos.z);
  err = pos.distanceTo(destination);
  Serial.println("Error: ");
  Serial.println(err);
}

void loop() {
  delay(1000);
}
