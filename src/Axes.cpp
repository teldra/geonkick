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

#include "Axes.h"

Axes::Axes()
        : xScale{std::make_unique<Scale>()}
        , yScale{std::make_unique<Scale>()}
{
}

Axes::~Axes()
{
}

void Axes::setXScale(std::unique_ptr<Scale> scale)
{
        xScale = std::move(scale);
}

Scale* Axes::getXScale() const
{
        return xScale.get();
}

Scale* Axes::getYScale() const
{
        return yScale.get();
}

void Axes::setYScale(std::unique_ptr<Scale> scale)
{
        yScale = std::move(scale);
}

RkPoint Axes::origin() const
{
        return {position().x() + padding().left(),
                position().y() + size().height() - 1 - padding().bottom()};
}

void Axes::draw(RkPainter &painter)
{
        dawCoordinate(painter);
        dawXScaleLines(painter);
        dawYScaleLines(painter);
}

const RkRect& Axes::padding() const
{
        return axesPadding;
}

void Axes::setPadding(const RkRect &pad)
{
        axesPadding = pad;
}

void Axes::dawCoordinate(RkPainter &painter)
{
        auto pen = painter.pen();
        pen.setColor(RkColor(125, 125, 125));
        pen.setWidth(1);
        painter.setPen(pen);
        painter.drawLine(position().x() + padding().left(),
                         position().y() + size().height() - 1 - padding().bottom(),
                         position().x() + size().width() - 1 - padding().right(),
                         position().y() + size().height() - 1 - padding().bottom());
        painter.drawLine(position().x() + padding().left(),
                         position().y() + size().height() - 1 - padding().bottom(),
                         position().x() + padding().left(),
                         position().y() + padding().top());
}

void Axes::dawXScaleLines(RkPainter &painter)
{
        
}

void Axes::dawYScaleLines(RkPainter &painter)
{
        
}


