/*****************************************************************************
 *
 * outputTIFF.h -- class declaration
 *
 * Copyright 2013,2014,2015,2016,2017,2018,2019
 *   James Fidell (james@openastroproject.org)
 *
 * License:
 *
 * This file is part of the Open Astro Project.
 *
 * The Open Astro Project is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Open Astro Project is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Open Astro Project.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#pragma once

extern "C" {
#include "tiffio.h"
}

#include "trampoline.h"


class OutputTIFF : public OutputHandler
{
  public:
    			OutputTIFF ( int, int, int, int, int, const char*, const char*,
							QString, trampolineFuncs* );
    			~OutputTIFF();
    int			openOutput ( void );
    int			addFrame ( void*, const char*, int64_t, const char*,
								FRAME_METADATA* );
    void		closeOutput ( void );
    int			outputExists ( void );
    int			outputWritable ( void );

  private:
    int			xSize;
    int			ySize;
    int			pixelDepth;
    int			validFileType;
    int			reverseByteOrder;
    int			swapRedBlue;
    int			colour;
    int			frameSize;
    unsigned char*	writeBuffer;
		const char*	applicationName;
		const char*	applicationVersion;
};
