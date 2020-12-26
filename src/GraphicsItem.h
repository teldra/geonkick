/**
 * File name: GraphicsItem.h
 * Project: Geonkick (A kick synthesizer)
 *
 * Copyright (C) 2020 Iurie Nistor <http://iuriepage.wordpress.com>
 *
 * This file is part of Geonkick.
 *
 * GeonKick is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef GEONKICK_GRAPHICS_ITEM_H
#define GEONKICK_GRAPHICS_ITEM_H

#include "globals.h"

#include <RkPainter.h>
#include <RkSize.h>
#include <RkPoint.h>

class GraphicsItem
{
 public:
        GraphicsItem();
        virtual ~GraphicsItem();
        virtual void draw(RkPainter &painter) = 0;
        const RkSize& size() const;
        void setSize(const RkSize &s);
        const RkPoint& position() const;
        void setPosition(const RkPoint &p);

 private:
        RkSize itemSize;
        RkPoint itemPosition;
};

#endif // GEONKICK_GRAPHICS_ITEM_H
