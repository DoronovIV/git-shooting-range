#ifndef SCHEDULE_SORTER_H
#define SCHEDULE_SORTER_H


#include <string>
#include <vector>

#include "../Wrappers/ScheduleDecorator.h"
#include "../Wrappers/EnumAdapter.h"


#ifndef using_sorter
#define using_sorter ScheduleSorter* sorter = ScheduleSorter::getInstance()
#endif



class ScheduleSorter
{


public:

	void sort(std::string sOptionName, vector<ScheduleDecorator*>& vSchedulesArray);

	//����������� ��������� ������;
	static ScheduleSorter* getInstance();

private:

	void sortBySpeciesName(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByRevenue(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByFertilizer(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByChemicals(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByPlantingPrice(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortBySoilNeed(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByHardwork(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByQuantity(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByVerminExposure(vector<ScheduleDecorator*>& vSchedulesArray);

	void sortByTime(vector<ScheduleDecorator*>& vSchedulesArray);


	// ��������� ������;
	static ScheduleSorter* instance;

	// ����������� �� ���������;
	ScheduleSorter();

	// ����������;
	virtual ~ScheduleSorter();


};



#endif