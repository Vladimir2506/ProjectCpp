#include <QtWidgets>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "Cafeteria.h"

using std::make_pair;

//Some useful functions
QString str2qstr(const string &str);
string qstr2str(const QString &qstr);

//Id regulations
enum IDGENERATOR
{
	ID_COMMENT,
	ID_CUISINE,
	ID_ORDER,
	ID_CUSTOMER,
	ID_COOK,
	ID_WAITOR,
	ID_MANAGER,
	ID_MAINTAINER
};
enum CharSel { CH_CUSTOMER, CH_MAINTAINER, CH_COOK, CH_WAITOR, CH_MANAGER };
string IdGenerator(int nChar, size_t nRecord, int nDigits = 6);
