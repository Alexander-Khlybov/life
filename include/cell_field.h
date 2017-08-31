#pragma once

#define BASE_CELLS_FIELD_HEIGHT
#define BASE_CELLS_FIELD_WIDTH

typedef pair<size_t, size_t> CLCS; //Cell coordinates
typedef size_t* VEC;

class CellsField {
public:
    CellsField (size_t height = BASE_CELLS_FIELD_HEIGHT, size_t width = BASE_CELLS_FIELD_WIDTH);
    CellsField (const CellsField& cellsfield);
    ~CellsField (void);

    // getting height and width of cells field
    size_t getHeight (void);
    size_t getWidth (void);

    // access to data and change data of cells field
    void setCellData (const CLCS& cellCoord, size_t cellValue);
    size_t getCellData (const CLCS& cellCoord);

    // getting Moore neighborhood of the first order: cells field 3x3
    CellsField getMooreNeighborhoodOf1stOrder (const CLCS& cellCoord);

    cellsField& operator= (const CellsField& cellsfield);
private:
    size_t** cellsField;
    size_t cfHeight;
    size_t cfWidth;
};
