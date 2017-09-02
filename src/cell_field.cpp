#include "..\\include\\cell_field.h"

CellsField::CellsField (size_t height, size_t width){
    cfHeight = height;
    cfWidth = width;
    cellsField = new size_t*[height];
    if (cellsField == NULL){
        throw exception("Bad memory allocation.\n");
    }

	for (size_t i = 0; i < height; i++){
        cellsField[i] = new size_t[width];
        if (cellsField[i] == NULL){
            throw exception("Bad memory allocation.\n");
        }

        for (size_t j = 0; j < width; j++){
           cellsField[i][j] = 0;
        }
    }
}

CellsField::CellsField (const CellsField& cellsfield){
    cfHeight = cellsfield.cfHeight;
    cfWidth = cellsfield.cfWidth;
    cellsField = new size_t*[cfHeight];
    if (cellsField == NULL){
        throw exception("Bad memory allocation.\n");
    }

    for (size_t i = 0; i < cfHeight; i++){
        cellsField[i] = new size_t[cfWidth];
        if (cellsField[i] == NULL){
            throw exception("Bad memory allocation.\n");
        }

        for (size_t j = 0; j < cfWidth; j++){
            cellsField[i][j] = cellsfield.cellsField[i][j];
        }
    }
}

CellsField::~CellsField (void){
    for (size_t i = 0; i < cfHeight; i++){
        delete[] cellsField[i];
        cellsField[i] = NULL;
    }
    delete[] cellsField;
    cellsField = NULL;
}

size_t CellsField::getHeight (void)const {
    return cfHeight;
}

size_t CellsField::getWidth (void)const {
    return cfWidth;
}

void CellsField::setCellData (const CLCS& cellCoord, size_t cellValue){
    size_t  height  =   cellCoord.first % cfHeight,
            width   =   cellCoord.second % cfWidth;

    cellsField[height][width] = cellValue;
}

size_t CellsField::getCellData (const CLCS& cellCoord)const {
    size_t  height  =   cellCoord.first % cfHeight,
            width   =   cellCoord.second % cfWidth;

    return cellsField[height][width];
}

CellsField& CellsField::operator= (const CellsField& cellsfield){
    if (this != &cellsfield){
        for (size_t i = 0; i < cfHeight; i++){
            delete[] cellsField[i];
            cellsField[i] = NULL;
        }
        delete[] cellsField;
        cellsField = NULL;

        cfHeight    = cellsfield.cfHeight;
        cfWidth     = cellsfield.cfWidth;

        cellsField = new size_t*[cfHeight];
        if (cellsField == NULL){
            throw exception ("Bad memory allocation.\n");
        }

        for (size_t i = 0; i < cfHeight; i++){
            cellsField[i] = new size_t[cfWidth];
            if (cellsField[i] == NULL){
                throw exception("Bad memory allocation.\n");
            }

            for (size_t j = 0; j < cfWidth; j++){
                cellsField[i][j] = cellsfield.cellsField[i][j];
            }
        }
    }
    return *this;
}

CellsField getMooreNeighborhoodOf1stOrder (const CLCS& cellCoord)const{
    //TODO
    return CellsField();
}
