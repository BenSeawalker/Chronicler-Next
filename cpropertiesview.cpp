#include "cpropertiesview.h"

#include "cstorybubble.h"

CPropertiesView::CPropertiesView(QStringListModel *model, QWidget *parent) : QWidget(parent)
{
    m_storyProperties = new CStoryProperties(NULL, model, parent);
    m_storyProperties->setEnabled(false);

    m_layout = new QVBoxLayout(this);
    m_layout->addWidget(m_storyProperties);
    setLayout(m_layout);
}


//void CPropertiesView::ItemType(QGraphicsItem *item)
//{
//    CBubble::BType type = CBubble::None;

//    CBubble *bbl = qgraphicsitem_cast<CBubble *>(item);
//    if(bbl)
//        type = bbl->GetType();

//    return type;
//}



void CPropertiesView::SetBubble(CBubble *bbl)
{
    m_storyProperties->SetBubble(bbl);

    if(bbl)
    {
        m_layout->removeItem(m_layout->takeAt(0));
        switch(bbl->GetType())
        {
        case CBubble::Story:
            m_layout->addWidget(m_storyProperties);
        break;

        case CBubble::Condition:

        break;

        case CBubble::Action:

        break;
        }
    }
}


