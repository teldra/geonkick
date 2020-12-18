/**
 * File name: Scale.h
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

Scale::Scale()
        : scaleType{ScaleType::Linear}
        , startRange{0.0}
        , endRange{0.0}
        , showAxis {true}
        , showAxisValue{true}
        , showAxisValeLine{true}
{
}

void Scale::setName(const RkString &name)
{
        scaleName = name;
}

RkString Scale::name() const
{
        return scaleName;
}

void Scale::setRange(double from, int to)
{
        startRange = from;
        endRange   = to;
}

double Scale::getRangeFrom() const
{
        return startRange;
}

double Scale::getRangeTo() const
{
        return endRange;
}


void Scale::setValues(const std::vector<double> &values)
{
        axisValues.clear();
        for (const auto &val: values)
                axisValues.emplace_back(AxisValue(val));
        updateAxisValuesPosition();
        updateAxisValuesText();
}

void Scale::draw(RkPainter &painter)
{
        painter.translate(position());
        if (!scaleName.empty())
                drawName(painter);
        if (isShowAxis())
                drawAxis(painter);

        for (const auto &val: axisValues()) {
                if (val.value >= getRangeFrom() && val.value <= getRangeTo()) {
                        if (isShowAxisValue())
                                drawAxisValue(val);
                }
        }
        painter.translate(RkPoint(-position().x(), -position().y()));
}

void Scale::drawAxis(RkPainter &painter)
{
        if (orientation() == ScaleOrientation::Horizontal)
                painter.drawLine(0, 0, size().width() - 1, 0);
        else
                painter.drawLine(size().width() - 1, 0, size().width() - 1, size().height() - 1);
}
 
void Scale::drawAxisValue(RkPainter &painter, const std::vector<AvisValue> &val)
{
        RkFont font = painter.font();
        RkRect rect(val.position.x(), val.position.y() - font.size() / 2, 25, font.size());
        painter.drawText(rect, val.text);
}

void Scale::setSize(const RkSize &size)
{
        scaleSize = size;
        updateAxisValuesPosition();
}

RkSize& Scale::size() const
{
        return scaleSize;
}

void Scale::setPosition(const RkPoint &pos)
{
        scalePosition = pos;
}

RkPoint& Scale::position() const
{
        return scalePosition;
}

ScaleType Scale::type() const
{
        return scaleType;
}

void Scale::SetType(ScaleType type)
{
        scaletype = type;
}

bool Scale::isShowAxis() const
{
        return showAxis;
}
 
void Scale::setShowAxis(bool show = true)
{
        showAxis = show;
}
 
bool Scale::isShowAxisValue() const
{
        return showAxisValue;
}
 
void Scale::setShowAxisValue(bool show = true)
{
        showAxisValue = true;
}
 
bool Scale::isShowAxisValeLine() const
{
        return showAxisValeLine;
}
 
void Scale::setShowAxisValeLine(bool show = true)
{
        showAxisValeLine = show;
}

