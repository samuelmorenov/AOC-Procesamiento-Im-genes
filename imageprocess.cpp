/***************************************************************************
 *   Copyright (C) 2011 by pilar   *
 *   pilarb@unex.es   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "imageprocess.h"


void imageprocess::copiar(uchar * imgO, uchar * imgD)
{
	asm volatile(
		"movl %0, %%esi \n\t"	
		"movl %1, %%edi \n\t"	
		"movl $320*240, %%ecx\n\t"
		"bcopia:"
		"movb (%%esi), %%al \n\t"
		"movb %%al, (%%edi) \n\t"
		"incl %%esi \n\t"
		"incl %%edi \n\t"
		"loop bcopia \n\t"
		: 
		: "m" (imgO),	"m" (imgD)
		: "%eax", "%ecx", "%esi", "%edi", "memory"

);


}


void imageprocess::negar(uchar * imgO, uchar * imgD)
{
	asm volatile(
        "\n\t"

        :
	: "m" (imgO),	"m" (imgD)
        : "memory"

);


}

void imageprocess::recortar(uchar * imgO, uchar * imgD, int cI, int fI, int w, int h)
{

    asm volatile(
        "\n\t"

        :
        : "m" (imgO),	"m" (imgD), "m" (cI), "m" (fI), "m" (w), "m" (h)
        : "memory"

);


}


void imageprocess::voltearHorizontal(uchar * imgO, uchar * imgD)
{
	asm volatile(
        "\n\t"

        :
	: "m" (imgO),	"m" (imgD)
        : "memory"

);


}

void imageprocess::voltearVertical(uchar * imgO, uchar * imgD)
{
	asm volatile(
        "\n\t"

        :
	: "m" (imgO),	"m" (imgD)
	: "%eax", "%ebx", "%ecx", "%esi", "%edi", "memory"

);


}


void imageprocess::girarIzquierda(uchar * imgO, uchar * imgD)
{

	asm volatile(
        "\n\t"

        :
	: "m" (imgO),	"m" (imgD)
        : "memory"

);


}

void imageprocess::girarDerecha(uchar * imgO, uchar * imgD)
{

	asm volatile(
        "\n\t"

        :
	: "m" (imgO),	"m" (imgD)
        : "memory"

);


}

void imageprocess::calcularHistograma(uchar * imgO, int * histoO)
{
    asm volatile(
        "\n\t"

        :
        : "m" (imgO),	"m" (histoO)
        : "memory"

);

}

void imageprocess::calcularUmbral(int * histoO, uchar & umbral)
{

    asm volatile(
        "\n\t"

        : "=m" (umbral)
        : "m" (histoO)
        : "memory"
    );

}

void imageprocess::umbralizar(uchar * imgO, uchar umbral, uchar * imgD)
{
    asm volatile(
        "\n\t"

        :
        : "m" (imgO), "m" (umbral), "m" (imgD)
        : "memory"
    );

}

