#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QPainter>
#include <QVector>
#include <QPointF>
#include <QLabel>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QSpinBox>

// 散点图绘制类
class ScatterPlotWidget : public QWidget {
public:
    ScatterPlotWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // 默认设置
        xMin = 0; // X轴最小值
        xMax = 100; // X轴最大值
        yMin = 0; // Y轴最小值
        yMax = 100; // Y轴最大值
        xInterval = 10; // X轴刻度间隔
        yInterval = 10; // Y轴刻度间隔
        title = "散点图"; // 图表标题
        xLabel = "X轴"; // X轴标签
        yLabel = "Y轴"; // Y轴标签
        pointSize = 5; // 点的大小
        lineWidth = 2; // 线条宽度
        showGrid = false; // 是否显示网格
        showLabels = true; // 是否显示标签
    }

    // 设置数据点
    void setData(const QVector<QPointF> &data) {
        m_data = data;
        update(); // 更新绘图
    }

    // 设置图表标题
    void setTitle(const QString &t) { title = t; }
    // 设置X轴标签
    void setXLabel(const QString &label) { xLabel = label; }
    // 设置Y轴标签
    void setYLabel(const QString &label) { yLabel = label; }
    // 设置X轴范围和间隔
    void setXRange(double min, double max, double interval) { xMin = min; xMax = max; xInterval = interval; }
    // 设置Y轴范围和间隔
    void setYRange(double min, double max, double interval) { yMin = min; yMax = max; yInterval = interval; }
    // 设置点的大小
    void setPointSize(int size) { pointSize = size; }
    // 设置线条宽度
    void setLineWidth(int width) { lineWidth = width; }
    // 设置是否显示网格
    void setShowGrid(bool show) { showGrid = show; }
    // 设置是否显示标签
    void setShowLabels(bool show) { showLabels = show; }

protected:
    // 绘制事件
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing); // 开启抗锯齿

        if (showGrid) {
            drawGrid(painter); // 绘制网格
        }

        drawAxes(painter); // 绘制坐标轴
        drawTrendLine(painter); // 绘制趋势线

        // 设置点的颜色和大小
        painter.setPen(Qt::red);
        painter.setBrush(Qt::red);

        // 绘制每个数据点
        for (const QPointF &point : m_data) {
            int x = static_cast<int>((point.x() - xMin) / (xMax - xMin) * (width() - 80) + 40);
            int y = static_cast<int>((1.0 - (point.y() - yMin) / (yMax - yMin)) * (height() - 80) + 40);
            painter.drawEllipse(QPoint(x, y), pointSize, pointSize); // 绘制点
        }

        // 绘制标题
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12));
        painter.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, title); // 绘制标题
    }

private:
    QVector<QPointF> m_data; // 存储数据点
    double xMin, xMax, yMin, yMax; // 坐标轴范围
    double xInterval, yInterval; // 坐标轴间隔
    QString title, xLabel, yLabel; // 图表标题和坐标轴标签
    int pointSize; // 点的大小
    int lineWidth; // 线条宽度
    bool showGrid; // 是否显示网格
    bool showLabels; // 是否显示标签

    // 绘制坐标轴
    void drawAxes(QPainter &painter) {
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));

        // 绘制X轴
        painter.drawLine(40, height() - 40, width() - 40, height() - 40);
        // 绘制Y轴
        painter.drawLine(40, 40, 40, height() - 40);

        // 添加坐标轴标签
        painter.drawText(width() - 100, height() - 5, xLabel);
        painter.drawText(10, 25, yLabel);

        // 绘制X轴刻度线和标签
        for (double i = xMin; i <= xMax; i += xInterval) {
            int x = static_cast<int>((i - xMin) / (xMax - xMin) * (width() - 80) + 40);
            painter.drawLine(x, height() - 40, x, height() - 35);
            if (showLabels) {
                painter.drawText(x - 10, height() - 20, QString::number(i)); // 绘制X轴标签
            }
        }

        // 绘制Y轴刻度线和标签
        for (double i = yMin; i <= yMax; i += yInterval) {
            int y = static_cast<int>((1.0 - (i - yMin) / (yMax - yMin)) * (height() - 80) + 40);
            painter.drawLine(40, y, 45, y);
            if (showLabels) {
                painter.drawText(10, y + 5, QString::number(i)); // 绘制Y轴标签
            }
        }
    }

    // 绘制网格
    void drawGrid(QPainter &painter) {
        painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));

        // 绘制水平网格线
        for (double i = yMin; i <= yMax; i += yInterval) {
            int y = static_cast<int>((1.0 - (i - yMin) / (yMax - yMin)) * (height() - 80) + 40);
            painter.drawLine(40, y, width() - 40, y); // 绘制水平网格线
        }

        // 绘制垂直网格线
        for (double i = xMin; i <= xMax; i += xInterval) {
            int x = static_cast<int>((i - xMin) / (xMax - xMin) * (width() - 80) + 40);
            painter.drawLine(x, 40, x, height() - 40); // 绘制垂直网格线
        }
    }

    // 绘制趋势线
    void drawTrendLine(QPainter &painter) {
        if (m_data.size() < 2) return; // 至少需要两个点

        // 计算线性回归
        double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
        for (const QPointF &point : m_data) {
            sumX += point.x();
            sumY += point.y();
            sumXY += point.x() * point.y();
            sumXX += point.x() * point.x();
        }
        int n = m_data.size();
        double slope = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX); // 计算斜率
        double intercept = (sumY - slope * sumX) / n; // 计算截距

        // 绘制趋势线
        painter.setPen(QPen(Qt::green, lineWidth));
        int x1 = 40;
        int y1 = static_cast<int>((1.0 - (slope * xMin + intercept - yMin) / (yMax - yMin)) * (height() - 80) + 40);
        int x2 = width() - 40;
        int y2 = static_cast<int>((1.0 - (slope * xMax + intercept - yMin) / (yMax - yMin)) * (height() - 80) + 40);
        painter.drawLine(x1, y1, x2, y2); // 绘制趋势线
    }
};

// 主窗口类
class MainWindow : public QWidget {
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // 散点图部分
        scatterPlot = new ScatterPlotWidget(this);
        mainLayout->addWidget(scatterPlot);

        // 数据输入部分
        QHBoxLayout *inputLayout = new QHBoxLayout();
        xInput = new QLineEdit(this);
        yInput = new QLineEdit(this);
        QPushButton *addButton = new QPushButton("添加数据", this);

        inputLayout->addWidget(new QLabel("X:", this));
        inputLayout->addWidget(xInput);
        inputLayout->addWidget(new QLabel("Y:", this));
        inputLayout->addWidget(yInput);
        inputLayout->addWidget(addButton);

        mainLayout->addLayout(inputLayout);

        // 设置图表属性
        QHBoxLayout *settingsLayout = new QHBoxLayout();
        QDoubleSpinBox *xMinSpin = new QDoubleSpinBox(this);
        QDoubleSpinBox *xMaxSpin = new QDoubleSpinBox(this);
        QDoubleSpinBox *yMinSpin = new QDoubleSpinBox(this);
        QDoubleSpinBox *yMaxSpin = new QDoubleSpinBox(this);
        QSpinBox *xIntervalSpin = new QSpinBox(this);
        QSpinBox *yIntervalSpin = new QSpinBox(this);
        QSpinBox *pointSizeSpin = new QSpinBox(this);
        QSpinBox *lineWidthSpin = new QSpinBox(this);
        QComboBox *fontSizeCombo = new QComboBox(this);

        // 设置范围
        xMinSpin->setRange(0, 300);
        xMaxSpin->setRange(0, 300);
        yMinSpin->setRange(0, 100);
        yMaxSpin->setRange(0, 100);
        xIntervalSpin->setRange(1, 50);
        yIntervalSpin->setRange(1, 50);
        pointSizeSpin->setRange(1, 20);
        lineWidthSpin->setRange(1, 10);
        fontSizeCombo->addItems({"8", "10", "12", "14", "16", "18", "20"});

        // 添加设置控件
        settingsLayout->addWidget(new QLabel("X最小值:", this));
        settingsLayout->addWidget(xMinSpin);
        settingsLayout->addWidget(new QLabel("X最大值:", this));
        settingsLayout->addWidget(xMaxSpin);
        settingsLayout->addWidget(new QLabel("Y最小值:", this));
        settingsLayout->addWidget(yMinSpin);
        settingsLayout->addWidget(new QLabel("Y最大值:", this));
        settingsLayout->addWidget(yMaxSpin);
        settingsLayout->addWidget(new QLabel("X间隔:", this));
        settingsLayout->addWidget(xIntervalSpin);
        settingsLayout->addWidget(new QLabel("Y间隔:", this));
        settingsLayout->addWidget(yIntervalSpin);
        settingsLayout->addWidget(new QLabel("点大小:", this));
        settingsLayout->addWidget(pointSizeSpin);
        settingsLayout->addWidget(new QLabel("线宽:", this));
        settingsLayout->addWidget(lineWidthSpin);
        settingsLayout->addWidget(new QLabel("字体大小:", this));
        settingsLayout->addWidget(fontSizeCombo);

        mainLayout->addLayout(settingsLayout);

        // 连接信号槽
        connect(addButton, &QPushButton::clicked, this, &MainWindow::addDataPoint);
        connect(xMinSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [=](double value) {
            scatterPlot->setXRange(value, xMaxSpin->value(), xIntervalSpin->value());
        });
        connect(xMaxSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [=](double value) {
            scatterPlot->setXRange(xMinSpin->value(), value, xIntervalSpin->value());
        });
        connect(yMinSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [=](double value) {
            scatterPlot->setYRange(value, yMaxSpin->value(), yIntervalSpin->value());
        });
        connect(yMaxSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [=](double value) {
            scatterPlot->setYRange(yMinSpin->value(), value, yIntervalSpin->value());
        });
        connect(xIntervalSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value) {
            scatterPlot->setXRange(xMinSpin->value(), xMaxSpin->value(), value);
        });
        connect(yIntervalSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value) {
            scatterPlot->setYRange(yMinSpin->value(), yMaxSpin->value(), value);
        });
        connect(pointSizeSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value) {
            scatterPlot->setPointSize(value);
        });
        connect(lineWidthSpin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value) {
            scatterPlot->setLineWidth(value);
        });
    }

private slots:
    // 添加数据点
    void addDataPoint() {
        bool xOk, yOk;
        double x = xInput->text().toDouble(&xOk);
        double y = yInput->text().toDouble(&yOk);

        if (xOk && yOk && x >= 0 && x <= 300 && y >= 0 && y <= 100) {
            data.append(QPointF(x, y)); // 添加数据点
            scatterPlot->setData(data); // 更新散点图
            xInput->clear();
            yInput->clear();
        } else {
            QMessageBox::warning(this, "输入错误", "请输入有效X值和有效Y值。");
        }
    }

private:
    ScatterPlotWidget *scatterPlot; // 散点图对象
    QLineEdit *xInput; // X输入框
    QLineEdit *yInput; // Y输入框
    QVector<QPointF> data; // 存储数据点
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // 创建应用程序

    MainWindow window; // 创建主窗口
    window.resize(800, 600); // 设置窗口大小
    window.show(); // 显示窗口

    return app.exec(); // 进入事件循环
}
