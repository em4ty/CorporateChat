#ifndef UTILS_H
#define UTILS_H

#include <QPixmap>
#include <QPainter>
#include <QColor>

inline QPixmap generateAvatar(const QString &username, int size = 40)
{
    QPixmap pixmap(size, size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor color = QColor::fromHsv(qAbs(username.length() * 37) % 360, 180, 200);
    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(0, 0, size, size);

    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", size * 0.5, QFont::Bold));
    painter.drawText(pixmap.rect(), Qt::AlignCenter, username.left(1).toUpper());

    return pixmap;
}

#endif // UTILS_H
