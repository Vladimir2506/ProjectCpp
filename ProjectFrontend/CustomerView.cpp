#include "stdafx.h"
#include "CustomerView.h"

CustomerView::CustomerView(QWidget *parent)
	: QDialog(parent),
	pCustomer(dynamic_cast<Customer*>(MainLogic::GetInstance()->pUser)),
	pWaiter(nullptr),
	icoCategories
	{ 
		QIcon("Resources/STPL.png"),
		QIcon("Resources/MEAT.png"),
		QIcon("Resources/VEGE.png"),
		QIcon("Resources/DESS.png"),
		QIcon("Resources/BEVE.png"),
		QIcon("Resources/SOUP.png"),
		QIcon("Resources/SEAF.png"),
		QIcon("Resources/SETM.png")
	},
	qstrCategories{ "主食","肉","蔬菜","甜品","饮料","汤","海鲜","套餐" }
{
	ui.setupUi(this);
	switch (pCustomer->GetState())
	{
	case CSSTATE::Absent:
		PhaseSeatPick();
		break;
	case CSSTATE::Make:
		PhaseOrderMake();
		break;
	case CSSTATE::Eat:
		PhaseMealEat();
		break;
	default:
		break;
	}
}

CustomerView::~CustomerView()
{
	pCustomer = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void CustomerView::paintEvent(QPaintEvent * event)
{
	ui.btnAddWater->setDisabled(pWaiter == nullptr);
	ui.btnHasten->setDisabled(pWaiter == nullptr);
	ui.btnPackUp->setDisabled(pWaiter == nullptr);
	ui.btnSubmit->setDisabled(dTotal < LDBL_EPSILON && dTotal > -LDBL_EPSILON );
	ui.btnFinish->setDisabled(ui.pbGeneral->value() != 100);
	ui.btnComWaiter->setDisabled(pWaiter == nullptr);
	QDialog::paintEvent(event);
}

void CustomerView::SubmitOrder()
{
	auto ret = QMessageBox::information(this, "支付确认",
		QString("您将支付%0元，请确认支付！").arg(pCustomer->m_itNow->second.CheckOut()),
		QMessageBox::Yes | QMessageBox::No);
	if (ret == QMessageBox::Yes)
	{
		for (auto & s : pCustomer->m_itNow->second.GetFoodMap())
		{
			pCustomer->m_statusComment[s.first.GetId()];
		}
		PhaseMealEat();
	}
}

void CustomerView::PhaseSeatPick()
{
	auto st = pCustomer->GetTableNum();
	if (st != -1)
	{
		MainLogic::GetInstance()->arrSeatVacance[st] = 1;
		st = -1;
	}
	HideAll();
	MyResize(600, 850);
	ui.gbSeatPick->show();
	ui.lblHint->show();
	ui.lblInfo->show();
	ui.btnProfile->show();
	nSeat = MainLogic::GetInstance()->arrSeatVacance.size();
	ui.lblInfo->setText("欢迎光临！尊敬的顾客" + str2qstr(pCustomer->GetName()) + "！");
	PrepareSeats();
	if (IsNoVacance())
	{
		ui.lblHint->setText("很抱歉，现在没有空闲座位，请您耐心等待……");
	}
	else
	{
		ui.lblHint->setText("请您在下方的餐桌列表中挑选座位！");
	}
}

void CustomerView::PhaseOrderMake()
{
	HideAll();
	MyResize(900, 900);
	ui.gbMenu->show();
	ui.lblInfo->show();
	PrepareMenu();
	ui.lblInfo->setText(QString("您好！尊敬的顾客%0，您的桌号为%1").
		arg(str2qstr(pCustomer->GetName())).
		arg(pCustomer->GetTableNum() + 1));
	dTotal = 0;
	ui.lblTotal->setText(QString("总计：%0元").arg(dTotal));
}

void CustomerView::PhaseMealEat()
{
	HideAll();
	MyResize(1000, 750);
	ui.gbOrder->show();
	ui.gbInstruction->show();
	ui.lblInfo->show();
	auto idWaiter = pCustomer->MakeOrder();
	if (idWaiter != "")
	{
		pWaiter = &MainLogic::s_currentWaiters[idWaiter];
		pCustomer->m_waiterComment[idWaiter];
		ui.lblWaiter->setText("服务员" + str2qstr(pWaiter->GetName()) + "为您服务！");
		pCustomer->m_itNow->second.Assign();
	}
	else
	{
		pWaiter = nullptr;
		ui.lblWaiter->setText("暂无服务员为您服务！");
	}
	ui.lblInfo->setText(QString("您好！尊敬的顾客%0，您的桌号为%1").
		arg(str2qstr(pCustomer->GetName())).
		arg(pCustomer->GetTableNum() + 1));
	PrepareOrder();
}

void CustomerView::OnPackUp()
{
	pWaiter->m_deqTodo.push_back(SRVS::Package);
	QMessageBox::information(this, "通知", "信息 打包 已发送给服务员！");
}

void CustomerView::OnAddWater()
{
	pWaiter->m_deqTodo.push_back(SRVS::Water);
	QMessageBox::information(this, "通知", "信息 加水 已发送给服务员！");
}

void CustomerView::OnHasten()
{
	pWaiter->m_deqTodo.push_back(SRVS::Hasten);
	QMessageBox::information(this, "通知", "信息 催单 已发送给服务员！");
}

void CustomerView::OnCommentDish()
{
	AddComment addc(IDGENERATOR::ID_CUISINE ,pCustomer, this);
	addc.exec();
}

void CustomerView::OnCommentWaiter()
{
	AddComment addc(IDGENERATOR::ID_WAITOR, pCustomer, this);
	addc.exec();
}


void CustomerView::OnFinish()
{
	pCustomer->Finish();
	pCustomer->m_itNow = MainLogic::s_currentOrders.end();
	pCustomer->m_statusComment.clear();
	accept();
}

void CustomerView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	ui.lblInfo->setText("欢迎光临！尊敬的" + str2qstr(pCustomer->GetName()) + "顾客");
}

void CustomerView::PrepareSeats()
{
	if (matSeat.isEmpty())
	{
		for (int i = 0; i < nSeat; ++i)
		{
			matSeat.push_back(new QPushButton(ui.gbSeatPick));
		}
	}
	int nCol = round(sqrt(nSeat));
	int nSize = 80, nDiv = 90;
	for (int i = 0; i < nSeat; ++i)
	{
		matSeat[i]->setGeometry(25 + (i % nCol) * nDiv, 25 + (i / nCol) * nDiv, nSize, nSize);
		matSeat[i]->setText(QString("桌号%0").arg(i + 1));
		matSeat[i]->show();
		matSeat[i]->setDisabled(MainLogic::GetInstance()->arrSeatVacance[i] == 0);
		connect(matSeat[i], &QPushButton::clicked, 
			//The slots by lambda expression
			[=]()
			{
				SeatClicked(i);
			});
	}
}


bool CustomerView::IsNoVacance()
{
	for (auto &t : MainLogic::GetInstance()->arrSeatVacance)
	{
		if (t == 1)
		{
			return false;
		}
	}
	return true;
}

void CustomerView::SeatClicked(int num)
{
	pCustomer->GetSeat(num, qstr2str(QDate::currentDate().toString("yyyy/MM/dd")));
	MainLogic::GetInstance()->arrSeatVacance[num] = 0;
	PhaseOrderMake();
}

void CustomerView::HideAll()
{
	//Hide all widgets
	ui.gbSeatPick->hide();
	ui.lblHint->hide();
	ui.lblInfo->hide();
	ui.gbMenu->hide();
	ui.gbInstruction->hide();
	ui.gbOrder->hide();
	ui.btnProfile->hide();
}

void CustomerView::PrepareMenu()
{
	ui.tbMenuDisp->setColumnCount(6);
	ui.tbMenuDisp->setHorizontalHeaderItem(0, new QTableWidgetItem("菜品类型"));			
	ui.tbMenuDisp->setHorizontalHeaderItem(1, new QTableWidgetItem("菜品名称"));
	ui.tbMenuDisp->setHorizontalHeaderItem(2, new QTableWidgetItem("价格（元/份）"));
	ui.tbMenuDisp->setHorizontalHeaderItem(3, new QTableWidgetItem("数量（份）"));
	ui.tbMenuDisp->setHorizontalHeaderItem(4, new QTableWidgetItem("小计（元）"));
	ui.tbMenuDisp->setHorizontalHeaderItem(5, new QTableWidgetItem("查看评论"));
	int nRow = 0;
	for (auto &dish : MainLogic::s_currentMenu)
	{
		ui.tbMenuDisp->setRowCount(1 + nRow);
		ui.tbMenuDisp->setItem(nRow, 0, new QTableWidgetItem(icoCategories[dish.second.GetCate()],qstrCategories[dish.second.GetCate()]));
		ui.tbMenuDisp->setItem(nRow, 1, new QTableWidgetItem(str2qstr(dish.second.GetName())));
		ui.tbMenuDisp->setItem(nRow, 2, new QTableWidgetItem(QString::number(dish.second.GetPrice())));
		QSpinBox *sbQuant = new QSpinBox(ui.tbMenuDisp);
		sbQuant->setMinimum(0);
		connect(sbQuant, static_cast<void(QSpinBox:: *)(int)>(&QSpinBox::valueChanged),
			//The slots by lambda expression
			[=](int nVal)
		{
			pCustomer->m_itNow->second.Adjust(dish.second, nVal);
			auto cost = pCustomer->m_itNow->second.m_mapBill[dish.first];
			ui.tbMenuDisp->setItem(nRow, 4, new QTableWidgetItem(QString::number(cost)));
			dTotal = pCustomer->m_itNow->second.CheckOut();
			ui.lblTotal->setText(QString("总计：%0元").arg(dTotal));
		});
		ui.tbMenuDisp->setCellWidget(nRow, 3, sbQuant);
		ui.tbMenuDisp->setItem(nRow, 4, new QTableWidgetItem("0"));
		QPushButton *btnComment = new QPushButton(ui.tbMenuDisp);
		btnComment->setText("查看评论");
		connect(btnComment, &QPushButton::clicked,
			//The slots by lambda expression
			[=]() 
		{
			BrowseComment bc(dish.first, this);
			bc.exec();
		});
		ui.tbMenuDisp->setCellWidget(nRow, 5, btnComment);
		++nRow;
	}
	ui.tbMenuDisp->setIconSize(QSize(25,25));
}

void CustomerView::MyResize(int w, int h)
{
	setMaximumSize(w, h);
	setMinimumSize(w, h);
	resize(w, h);
}

void CustomerView::PrepareOrder()
{
	ui.tbOrder->setColumnCount(3);
	ui.tbOrder->setHorizontalHeaderItem(0, new QTableWidgetItem("菜品"));
	ui.tbOrder->setHorizontalHeaderItem(1, new QTableWidgetItem("已点菜"));
	ui.tbOrder->setHorizontalHeaderItem(2, new QTableWidgetItem("已上菜"));
	int nRow = 0;
	auto foodOrdered = pCustomer->m_itNow->second.GetFoodMap();
	auto all = 0, served = 0;
	for (auto &fo : foodOrdered)
	{
		auto servedFood = fo.second - pCustomer->m_itNow->second.m_mapFoodToDo[fo.first];
		ui.tbOrder->setRowCount(1 + nRow);
		ui.tbOrder->setItem(nRow, 0, new QTableWidgetItem(str2qstr(fo.first.GetName())));
		ui.tbOrder->setItem(nRow, 1, new QTableWidgetItem(QString::number(fo.second)));
		ui.tbOrder->setItem(nRow, 2, new QTableWidgetItem(QString::number(servedFood)));
		++nRow;
		all += fo.second;
		served += servedFood;
	}
	ui.pbGeneral->setValue(100 * served / all);
}
