// #BEGIN_LICENSE
// fuzzylite: a fuzzy logic control library in C++
// Copyright (C) 2014  Juan Rada-Vilela
// 
// This file is part of fuzzylite.
//
// fuzzylite is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// fuzzylite is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with fuzzylite.  If not, see <http://www.gnu.org/licenses/>.
// #END_LICENSE

/*
 * Activated.h
 *
 *  Created on: 27/01/2014
 *      Author: jcrada
 */

#ifndef FL_ACTIVATED_H
#define FL_ACTIVATED_H

#include "fl/term/Term.h"

namespace fl {
    class TNorm;

    class FL_EXPORT Activated : public Term {
    protected:
        const Term* _term;
        scalar _degree;
        const TNorm* _activation;

    public:
        Activated(const Term* term = NULL, scalar degree = 1.0,
                const TNorm* activationOperator = NULL);

        virtual ~Activated();

        virtual std::string className() const;
        virtual std::string parameters() const;
        virtual void configure(const std::string& parameters);

        virtual scalar membership(scalar x) const;
        virtual std::string toString() const;

        virtual void setTerm(const Term* term);
        virtual const Term* getTerm() const;

        virtual void setDegree(scalar degree);
        virtual scalar getDegree() const;

        virtual void setActivation(const TNorm* activation);
        virtual const TNorm* getActivation() const;

        virtual Activated* clone() const;
    };

}
#endif /* FL_ACTIVATED_H */