#include "cstoryproperties.h"

#include "cstorybubble.h"

CStoryProperties::CStoryProperties(CBubble *bbl, QStringListModel *model, QWidget *parent)
    : QWidget(parent), m_model(model), m_title(0), m_story(0), m_lock(0), m_order(0)
{
    // WIDGETS
        // Title
        QLabel *lblTitle = new QLabel(tr("Title:"), this);
        m_title = new QLineEdit(this);
        connect(m_title, SIGNAL(textChanged(QString)), this, SLOT(TitleChanged(QString)));

        // Story
        QLabel *lblStory = new QLabel(tr("Story:"), this);
        m_story = new CTextEdit(this, m_model);
        connect(m_story, SIGNAL(textChanged()), this, SLOT(StoryChanged()));

        // Lock
        QLabel *lblLocked = new QLabel(tr("Locked:"), this);
        m_lock = new QCheckBox(this);
        m_lock->setFocusPolicy(Qt::NoFocus);
        connect(m_lock, SIGNAL(toggled(bool)), this, SLOT(LockedChanged(bool)));

        // Order
        QLabel *lblOrder = new QLabel(tr("Order:"), this);
        m_order = new QLineEdit(this);
        m_order->setValidator(new QIntValidator(0,9999999));
        m_order->setMaximumWidth(50);
        m_order->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        connect(m_order, SIGNAL(textChanged(QString)), this, SLOT(OrderChanged(QString)));


    // LABELS
        // Title
        QHBoxLayout *l1 = new QHBoxLayout();
        l1->addWidget(lblTitle);
        l1->addWidget(m_title);

        // Story
        QVBoxLayout *l2 = new QVBoxLayout();
        l2->addWidget(lblStory);
        l2->addWidget(m_story);

        // Order
        QHBoxLayout *l3 = new QHBoxLayout();
        l3->addWidget(lblOrder);
        l3->addWidget(m_order);

        // Lock
        QHBoxLayout *l4 = new QHBoxLayout();
        l4->addWidget(lblLocked);
        l4->addWidget(m_lock);
        l4->setAlignment(lblLocked, Qt::AlignRight);


//    // LAYOUT
    QVBoxLayout *lOrderLock = new QVBoxLayout();
    lOrderLock->addLayout(l3);
    lOrderLock->addLayout(l4);

    QHBoxLayout *lTitleOrder = new QHBoxLayout();
    lTitleOrder->addLayout(l1);
    lTitleOrder->addLayout(lOrderLock);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(lTitleOrder);
    layout->addLayout(l2);

    setLayout(layout);



    SetBubble(bbl);
}


void CStoryProperties::TitleChanged(QString title)
{
    if(m_bbl)
        m_bbl->m_title->SetText(title);
}

void CStoryProperties::StoryChanged()
{
    if(m_bbl)
        m_bbl->m_story->SetText(m_story->toPlainText());
}

void CStoryProperties::OrderChanged(QString order)
{
    if(m_bbl)
        m_bbl->m_order = order.toInt();
}

void CStoryProperties::LockedChanged(bool locked)
{
    if(m_bbl)
    {
        m_bbl->m_locked = locked;
        m_order->setEnabled(locked);
    }
}


void CStoryProperties::SetBubble(CBubble *bbl)
{
    m_bbl = qgraphicsitem_cast<CStoryBubble *>(bbl);

    if(m_bbl)
    {
        setEnabled(true);

        m_title->setText(m_bbl->m_title->Text());
        m_title->setFont(bbl->GetFont());
        m_title->setFocus();

        m_story->setText(m_bbl->m_story->Text());
        m_story->setFont(bbl->GetFont());

        m_lock->setChecked(m_bbl->m_locked);

        m_order->setText(QString().number(m_bbl->m_order));
        m_order->setEnabled(m_lock->isChecked());
    }
    else
    {
        m_title->setText(tr(""));
        m_story->setText(tr(""));
        m_lock->setChecked(false);
        m_order->setText(tr(""));

        setEnabled(false);
    }
}


void CStoryProperties::setFont(const QFont &font)
{
    QWidget::setFont(font);
    m_title->setFont(font);
    m_story->setFont(font);
    m_lock->setFont(font);
    m_order->setFont(font);
}


