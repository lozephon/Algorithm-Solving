#include "stdio.h"
#include <vector>
#include <algorithm>

typedef std::vector< std::pair< int, int > > CBlankCellList;

struct CResult
{
    int maxGunmans;
    int numCombinations;
    int currNumGunmans; // internal use
};

struct CSection
{
    int rowcol;    // 0~7
    int start;    // 0~7
    int len;    // 1~8
};

struct CIsInSection : public std::unary_function< CBlankCellList::value_type, bool >
{
    CIsInSection( const CBlankCellList::value_type & aCell ) : cell2nd( aCell ){}
    
    bool operator ()( const CBlankCellList::value_type & cell ) const
    {
        return( cell.first == cell2nd.first || cell.second == cell2nd.second );
    }
    
    const CBlankCellList::value_type & cell2nd;
};

void PermutateGunmans( const CBlankCellList & blankCells, CResult & result )
{
    CBlankCellList::const_iterator it( blankCells.begin() );
    CBlankCellList::const_iterator end( blankCells.end() );
    CBlankCellList subBlankCells;
    
    ++result.currNumGunmans;
    
    for( ; it != end; ++it )
    {
        { // intended nested block
            subBlankCells.resize( 0 );
            subBlankCells.insert( subBlankCells.end(), it + 1, end );
            CBlankCellList::iterator newEnd;
            newEnd = std::remove_if( subBlankCells.begin(), subBlankCells.end(), CIsInSection( *it ) );
            subBlankCells.erase( newEnd, subBlankCells.end() );
        }
        
        if( !subBlankCells.empty() )
        {
            PermutateGunmans( subBlankCells, result );
        }
        else if( result.currNumGunmans >= result.maxGunmans )
        {
            if( result.currNumGunmans > result.maxGunmans )
            {
                result.numCombinations = 1;
                result.maxGunmans = result.currNumGunmans;
            }
            else
            {
                result.numCombinations++;
            }
        }
    }
    
    --result.currNumGunmans;
}

void TranslateProblemSpace( const bool * fieldState, const int fieldSize, CBlankCellList & blankCells )
{
    std::vector< CSection > rowSections;
    std::vector< CSection > colSections;
    CSection section;
    
    for( int rowcol = 0; rowcol < fieldSize; ++rowcol )
    {
        section.rowcol = rowcol;
        section.start = 0;
        
        int col;
        for( col = 0; col < fieldSize; ++col ) // col
        {
            if( fieldState[rowcol * fieldSize + col] )
            {
                if( col > section.start )
                {
                    section.len = col - section.start;
                    rowSections.push_back( section );
                }
                section.start = col + 1;
            }
        }
        if( col > section.start )
        {
            section.len = col - section.start;
            rowSections.push_back( section );
        }
        
        section.start = 0;
        
        int row;
        for( row = 0; row < fieldSize; ++row ) // row
        {
            if( fieldState[row * fieldSize + rowcol] )
            {
                if( row > section.start )
                {
                    section.len = row - section.start;
                    colSections.push_back( section );
                }
                section.start = row + 1;
            }
        }
        if( row > section.start )
        {
            section.len = row - section.start;
            colSections.push_back( section );
        }
    }
    
    for( int row = 0; row < int( rowSections.size() ); ++row )
    {
        for( int col = 0; col < int( colSections.size() ); ++col )
        {
            int rowpos = colSections[col].rowcol - rowSections[row].start;
            int colpos = rowSections[row].rowcol - colSections[col].start;
            if( rowpos >= 0 && rowpos < rowSections[row].len && colpos >= 0 && colpos < colSections[col].len )
            {
                blankCells.push_back( std::make_pair( row, col ) );
            }
        }
    }
}

void FindMaximumNumberOfGunmans( const bool * fieldState, const int fieldSize, CResult & result )
{
    result.maxGunmans = 0;
    result.numCombinations = 0;
    result.currNumGunmans = 0;
    CBlankCellList blankCells;
    
    TranslateProblemSpace( fieldState, fieldSize, blankCells );
    PermutateGunmans( blankCells, result );
}

void PrintResult( const CResult & result )
{
    printf("Max Gunmans: %d\n", result.maxGunmans );
    printf("Number of Combinations: %d\n", result.numCombinations );
}

int main()
{
    static const int FIELD_SIZE = 8;
    
    static const bool c_FieldState[FIELD_SIZE * FIELD_SIZE] =
    {
        0,1,0,1,0,1,0,1,
        0,0,0,0,0,1,0,0,
        1,0,1,0,0,1,0,1,
        0,0,0,0,0,0,0,0,
        0,0,0,1,0,0,0,0,
        0,0,0,0,0,1,0,1,
        0,1,0,0,0,0,0,0,
        0,0,0,0,1,0,1,0
    };
    
    CResult result;
    
    FindMaximumNumberOfGunmans( &c_FieldState[0], FIELD_SIZE, result );
    
    PrintResult( result );
    
    return 0;
}