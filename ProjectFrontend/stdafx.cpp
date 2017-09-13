#include "stdafx.h"

QString str2qstr(const string & str)
{
	return QString::fromLocal8Bit(str.c_str());
}

string qstr2str(const QString & qstr)
{
	return string(qstr.toLocal8Bit());
}

