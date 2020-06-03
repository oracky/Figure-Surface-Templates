#pragma once
#include "Figura.h"
#include "Point.h"
#include "RegularPolygon.h"
#include "Square.h"
#include "Triangle.h"
#include "tests.h"

void test_static_Square_area();
void test_static_Point_Square_area();
void test_polymorphism_Square_area();
void test_static_Triangle_area();
void test_static_Point_Triangle_area();
void test_polymorphism_Triangle_area();
void test_static_RegularPolygon_area();
void test_static_Point_RegularPolygon_area();
void test_polymorphism_RegularPolygon_area();
void empty_object_test();

void RUNALLTESTS();