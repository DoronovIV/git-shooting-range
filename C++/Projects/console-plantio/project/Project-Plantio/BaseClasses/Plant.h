#ifndef PLANT_H
#define PLANT_H


#ifndef PLANTING_H
#include "Enums/Planting.h"
#endif


#ifndef COUNTRY_H
#include "Enums/Country.h"
#endif


#ifndef SPECIES_H
#include "Enums/Species.h"
#endif

#include "../Wrappers/EnumAdapter.h"


#include <iostream>

using namespace SpeciesEnum;

// ����� "��������", �� ����� ������ �������������, �������� ���������;
class Plant
{


public:



#pragma region GET

	//;
	//;
	Planting getPlantingMaterial();

	// ������ ����;
	// returns � ��� ��������;
	Species getSpecies();

	// ������ ������ ���������� ����������� ���������;
	// returns � ������ ����������;
	Country getMaterialCountry();

	// ������ ���������� ������������ ������ �����;
	// returns � ���������� ������;
	double getSoilNeedRatio();

	// ������ ���������� ������������ ���������;
	// returns � ���������� ��������� (� ������);
	size_t getFertilizerNeed();

	// ������ ���������� ������������ ��������;
	// returns � ���������� �������� (� ������);
	size_t getChemicalsNeed();

	// ������ ��������� ����������� ���������;
	// returns � ��������� ��������� (�� ����);
	double getPlantingPrice();

	//;
	//;
	double getPackagingPrice();

	// ������ ������� �����������;
	// returns � ����� �����������;
	size_t getGrowingTime();

	// ������ ���������� �������;
	// returns � �������;
	double getRevenue();

	// ������ ���������� ����������� �����������;
	// returns � ���������� ����������� (�����);
	size_t getSelfloadRequired();

	// ������ ���������� ������ �����������;
	// returns � ���������� ����������� (������ �� ����);
	double getHiredWorkload();

	// ������ ���������� � ���������� ;
	// returns � ����������� �������������� (� ������);
	size_t getVerminExposure();


#pragma endregion GET



#pragma region SET

	// ������ ����;
	// "eSpecies" � ��� ��������;
	void setSpecies(Species eSpecies);

	void setPlantingMaterial(Planting ePlantingMaterial);

	// ������ ������ ���������� ����������� ���������;
	// "ePlantingMaterialCountry" � ������ ����������;
	void setMaterialCountry(Country ePlantingMaterialCountry);

	// ������ ���������� ������������ ������ �����;
	// "dSoilNeedRatio" � ���������� ������;
	void setSoilNeedRatio(double dSoilNeedRatio);

	// ������ ���������� ������������ ���������;
	// "nFertilizerNeed" � ���������� ��������� (� ������);
	void setFertilizerNeed(size_t nFertilizerNeed);

	// ������ ���������� ������������ ��������;
	// "nChemicalsNeed" � ���������� �������� (� ������);
	void setChemicalsNeed(size_t nChemicalsNeed);

	// ������ ��������� ����������� ���������;
	// "dPlantingPrice" � ��������� ��������� (�� ����);
	void setPackagingPrice(double dPackagingPrice);

	// ������ ��������� ����������� ���������;
	// "dPlantingPrice" � ��������� ��������� (�� ����);
	void setPlantingPrice(double dPlantingPrice);

	// ������ ������� �����������;
	// "nGrowingTime" � ����� �����������;
	void setGrowingTime(size_t nGrowingTime);

	// ������ ���������� �������;
	// "dRevenuePerUnit" � �������;
	void setRevenue(double dRevenuePerUnit);

	// ������ ���������� ����������� �����������;
	// "nSelfloadRequired" � ���������� ����������� (�����);
	void setSelfloadRequired(size_t nSelfloadRequired);

	// ������ ���������� ������ �����������;
	// "nHiredWorkload" � ���������� ����������� (������ �� ����);
	void setHiredWorkload(double dHiredWorkload);

	// ������ ���������� � ���������� ;
	// "nVerminExposure" � ����������� �������������� (� ������);
	void setVerminExposure(size_t nVerminExposure);


#pragma endregion SET



#pragma region CONSTRUCTION

	// ����������� �� ���������;
	Plant();

	// ����������;
	virtual ~Plant();

	// ����������� �����������;
	// "anotherPlant" � ���������� ������;
	Plant(Plant& anotherPlant);

	// ���������� ��������� "=";
	// "anotherPlant" � ���������� ������;
	// returns � ����� �������;
	Plant& operator=(Plant& anotherPlant);


#pragma endregion CONSTRUCTION



protected:

	// ��� ����������� ���������;
	Planting ePlantingMaterial;

	// ������������� ��� ��������;
	Species eSpecies;

	// ������ ����������� ���������;
	Country ePlantingMaterialCountry;

	// ����������� � ���������� ����� (���� �� ���� ��������);
	double dSoilNeedRatio;

	// ����������� � ���������, � ������ �� 1 �� 5;
	size_t nFertilizerNeed;

	// ����������� � ������������, � ������ �� 1 �� 5;
	size_t nChemicalsNeed;

	// ��������� ����������� ��������� �� �����;
	double dPlantingPrice;

	double dPackagingPrice;

	// ����� �� ����������� (� ����);
	size_t nGrowingTime;

	// ������� �� ������� ������;
	double dRevenuePerUnit;

	// ���������� ����������� ����������� (� ������);
	size_t nSelfloadRequired;

	// ���������� ������ ����������� (� ������� �� ������� ������);
	double dHiredWorkload;

	// �������������� ����������; 
	size_t nVerminExposure;


};


#endif

