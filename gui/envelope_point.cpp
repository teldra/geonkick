#include "envelope_point.h"
#include "oscillator_envelope.h"

#include <QDebug>

OscillatorEnvelopePoint::OscillatorEnvelopePoint(void)
	: QPointF(),
	  is_selected(false),
	  pointRadius(7),
	  dotRadius(3),
	  parentEnvelope(NULL)

{
}

OscillatorEnvelopePoint::OscillatorEnvelopePoint(OscillatorEnvelope *parent,
						 const QPointF &point)
	: QPointF(point),
	  is_selected(false),
	  pointRadius(7),
	  dotRadius(3),
	  parentEnvelope(parent)
{
}

OscillatorEnvelopePoint::OscillatorEnvelopePoint(OscillatorEnvelope *parent,
						 double x, double y)
	: QPointF(x, y),
	  is_selected(false),
	  pointRadius(7),
	  dotRadius(3),
	  parentEnvelope(parent)

{
}

OscillatorEnvelopePoint::~OscillatorEnvelopePoint()
{
	
}

void OscillatorEnvelopePoint::draw(QPainter &painter)
{
	QPen pen;
	if (isSelected()) {
		pen.setWidth(2);
	} else {
		pen.setWidth(1);
	}

	painter.setPen(pen);
	painter.setBrush(Qt::white);
	QPointF point = scaleUp(QPointF(x(), y()));
	QPointF origin = parentEnvelope->getOriginPoint();
	QRectF rect;
	rect.setCoords(origin.x() + (point.x() - radius()),
		       origin.y() - (point.y() - radius()),
		       origin.x() + (point.x() + radius()),
		       origin.y() - (point.y() + radius()));
	painter.drawEllipse(rect);
	//QString textVal = QString::number(((parentEnvelope->kickLength() * x()) * 1000, 'f', 0) + " ms"; 
	//painter.drawText(origin.x() + (point.x() + 3 * radius() / 3),
	//		 origin.y() - (point.y() + 3 * radius() / 3),
	//		 );

	painter.setBrush(Qt::black);
	rect.setCoords(origin.x() + (point.x() - radius() / 3),
		       origin.y() - (point.y() - radius() / 3),
		       origin.x() + (point.x() + radius() / 3),
		       origin.y() - (point.y() + radius() / 3));
	painter.drawEllipse(rect);
}

QPointF OscillatorEnvelopePoint::scaleUp(QPointF point)
{
  return parentEnvelope->scaleUp(point);
}

double OscillatorEnvelopePoint::radius(void)
{
	return pointRadius;
}

double OscillatorEnvelopePoint::getDotRadius(void)
{
	return dotRadius;
}

bool OscillatorEnvelopePoint::isSelected(void)
{
	return is_selected;
}

void OscillatorEnvelopePoint::selectPoint(void)
{
	is_selected = true;
}

void OscillatorEnvelopePoint::unselectPoint(void)
{
	is_selected = false;
}

bool OscillatorEnvelopePoint::hasPoint(const QPointF &point)
{
	double px = point.x();
	double py = point.y();
	QPointF p = scaleUp(QPointF(x(), y()));
	qDebug() << "mouse(" << px << ", " << py << ") current(" << p.x() << ", " << p.y() << ")";
	
	if ((px > p.x() - pointRadius) && (px < p.x() + pointRadius)
	    && (py > y() - pointRadius) && (py < p.y() + pointRadius)
	    && (pow(p.x() - px, 2) + pow(p.y() - py, 2) < pow(pointRadius, 2)))
		{
		  qDebug() << "IS here";
			return true;
		}

	qDebug() << "NOT here";

	return false;
}

