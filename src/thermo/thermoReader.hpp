/*---------------------------------------------------------------------------*\
  c-o-o-c-o-o-o             |
  |     |     A utomatic    | Open Source Flamelet
  c-o-o-c     F lamelet     | 
  |     |     C onstructor  | Copyright (C) 2015 Holzmann-cfd
  c     c-o-o-o             |
-------------------------------------------------------------------------------
License
    This file is part of Automatic Flamelet Constructor.

    AFC is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 3 of the License, or 
    (at your option) any later version.

    AFC is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AFC; if not, see <http://www.gnu.org/licenses/>

Class
    AFC::ThermoReader    

Description
    Reading the chemkin III file

SourceFiles
    thermoReader.cpp

\*---------------------------------------------------------------------------*/

#ifndef ThermoReader_hpp
#define ThermoReader_hpp

#include "stringManipulator.hpp"
#include "thermoData.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace AFC
{

/*---------------------------------------------------------------------------*\
                      Class ThermoReader Declaration
\*---------------------------------------------------------------------------*/

class ThermoReader
:
    public StringManipulator
{
    private:

        //- List of available keywords for thermo
        wordList THERMO{ "THERMO", "THERMO ALL" };

        // Private data

            //- Thermo file
            string file_;


    public:

        // Constructor and Destructor

            //- Constructor with file string and Thermo:: obj adress
            ThermoReader
            (
                const string&
            );

            //- Destructor
            ~ThermoReader();

        
        // Member functions

            //- Read thermo file and return pointer to ThermoData:: obj
            void read
            (
                ThermoData&
            );

            //- Read file and get NASA polynomials
            void readNasaPolynomials
            (
                const stringList&
            );


        // Helper functions
        
            //- Find line number of keyword
            void findKeyword
            (
                int&,
                unsigned int&,
                const stringList&
            );

            //- Return the atomic weight of the atom
            scalar calcWeight
            (
                const word&,
                const string&,
                const word&
            );


        // Data manipulation functions

            //- NASAPolynomial reader for first line
            void NASAPolynomialNo1
            (
                const string&,
                const unsigned int&,
                ThermoData&
            );

            //- NASAPolynomial reader for second line
            void NASAPolynomialNo2
            (
                const string&,
                const unsigned int&,
                ThermoData&

            );

            //- NASAPolynomial reader for third line
            void NASAPolynomialNo3
            (
                const string&,
                const unsigned int&,
                ThermoData&

            );

            //- NASAPolynomial reader for fourth line
            void NASAPolynomialNo4
            (
                const string&,
                const unsigned int&,
                ThermoData&

            );

            //- Calculate molecular weight of species
            scalar calcMolecularWeight
            (
                const word&
            );
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace AFC

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
