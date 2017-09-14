#include"DataSet.h"
DataSet::DataSet()
{}
DataSet &DataSet::getInstance()
{
	static DataSet data;
	return data;
}
MAP_TEC &DataSet::getTecMap()
{
	return m_TecMap;
}
MAP_MANAGER &DataSet::getManagerMap()
{
	return m_ManagerMap;
}
MAP_SALE &DataSet::getSaleMap()
{
	return m_SaleMap;
}
MAP_SALEMANAGER &DataSet::getSaleManagerMap()
{
	return m_SaleManagerMap;
}
MAP_BOSS &DataSet::getBossMap()
{
	return m_BossMap;
}
