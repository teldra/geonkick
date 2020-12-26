/**
 * File name: Axes.h
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

#ifndef GEONKICK_AXES_H
#define GEONKICK_AXES_H

#include "GraphicsItem.h"
#include "Scale.h"

class Axes : public GraphicsItem
{
 public:
        Axes();
        ~Axes();
        Scale* getXScale() const;
        void setXScale(std::unique_ptr<Scale> scale);
        Scale* getYScale() const;
        void setYScale(std::unique_ptr<Scale> scale);
        RkPoint origin() const;
        void draw(RkPainter &painter) override;
        const RkRect& padding() const;
        void setPadding(const RkRect &pad);

 protected:
        void dawCoordinate(RkPainter &painter);
        void dawXScaleLines(RkPainter &painter);
        void dawYScaleLines(RkPainter &painter);
 private:
        std::unique_ptr<Scale> xScale;
        std::unique_ptr<Scale> yScale;
        RkRect axesPadding;
};

#endif // GEONKICK_AXES_H
