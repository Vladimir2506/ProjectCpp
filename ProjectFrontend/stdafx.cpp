#include "stdafx.h"

QString str2qstr(const string & str)
{
	return QString::fromLocal8Bit(str.c_str());
}

string qstr2str(const QString & qstr)
{
	return string(qstr.toLocal8Bit());
}

string IdGenerator(int nChar, size_t nRecord,int nDigits)
{
	string strRecord(std::to_string(nRecord + 1));
	size_t nCompensation = nDigits - 1 - strRecord.size();
	return std::to_string(nChar) + string(nCompensation, '0') + strRecord;
}