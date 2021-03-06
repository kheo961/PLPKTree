#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H


#include <QGraphicsView>
#include "Expression.h"
#include "Edge.h"
class Node;
class Expression;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = 0);

	void SetTree(std::vector<std::vector<Expression*>> tree);

    void ItemMoved();

	Node* GetRootNode();

	bool IsItemGrabbed();

public slots:
    void ZoomIn();
    void ZoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent * event) override;
    void timerEvent(QTimerEvent *event) override;

#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void ScaleView(qreal scaleFactor);

private:
    int timer_id;
    Node *root_node;
	std::vector<Node*> nodes;
	std::vector<Edge*> edges;
	float tree_level_height;
	float tree_nodes_width;
	int screen_height;
	int screen_width;

	QPoint origin;
};

#endif
