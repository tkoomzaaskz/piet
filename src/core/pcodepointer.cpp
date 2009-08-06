//// includes

// header file
#include "pcodepointer.h"

// piet core
#include "../debug.h"
#include "penums.h"

// C++
#include <iostream>

// STL
// none

// Qt
// none

PCodePointer::PCodePointer(QImage *code_image)
{
	debug("CONSTRUCTOR ----- code-pointer START\n");
	image = code_image; // referencja do obiektu obrazu kodu
	debug("CONSTRUCTOR ----- code-pointer END\n");
}

PCodePointer::~PCodePointer()
{
	debug("DESTRUCTOR ----- code-pointer START\n");

	debug("DESTRUCTOR ----- code-pointer END\n");
}

void PCodePointer::clear()
{
	coord_x = INIT_coord_x;
	coord_y = INIT_coord_y;
	codel_chooser = INIT_cc;
	direction_pointer = INIT_dp;
}

//==================================================================

QRgb PCodePointer::getPointedPixel()
{
	return image->pixel(coord_x, coord_y);
}

//==================================================================

void PCodePointer::setCodelChooser(PCodelChooserValues cc)
{
	codel_chooser = cc;
}

void PCodePointer::setDirectionPointer(PDirectionPointerValues dp)
{
	direction_pointer = dp;
}

void PCodePointer::turnDirectionPointerClockwise()
{
	switch (direction_pointer) {
		case dp_right:
			direction_pointer = dp_down;
			break;
		case dp_down:
			direction_pointer = dp_left;
			break;
		case dp_left:
			direction_pointer = dp_up;
			break;
		case dp_up:
			direction_pointer = dp_right;
			break;
	}
}

void PCodePointer::toggleCodelChooser()
{
	switch (codel_chooser) {
		case cc_left:
			codel_chooser = cc_right;
			break;
		case cc_right:
			codel_chooser = cc_left;
			break;
	}
}

//==================================================================

int PCodePointer::getCoordX()
{
	return coord_x;
}

int PCodePointer::getCoordY()
{
	return coord_y;
}

//==================================================================

void PCodePointer::__dev__printCoordinates()
{
	std::cout << "coordinates: x=" << coord_x << " y=" << coord_y << std::endl;
}

void PCodePointer::__dev__printConsole()
{
	std::cout << "code-pointer" <<  std::endl;
	__dev__printCoordinates();
}
