
#include "settingfilter.h"
#include "stringutils.h"

using namespace std;

SettingFilterMap::SettingFilterMap(const map<string, string>& filterMap)
    : m_filterMap(filterMap)
{
}

SettingFilterMap::~SettingFilterMap()
{
}

string SettingFilterMap::getId() const
{
    return "map";
}

void SettingFilterMap::setMap(const map<string, string>& filterMap)
{
    m_filterMap = filterMap;
}

const map<string, string>& SettingFilterMap::getMap() const
{
    return m_filterMap;
}

bool SettingFilterMap::filterWrite(string& valueNew)
{
    for(map<string, string>::const_iterator itMapping = m_filterMap.begin(); itMapping != m_filterMap.end(); ++itMapping)
    {
        if(itMapping->second == valueNew)
        {
            valueNew = itMapping->first;
            return true;
        }
    }

    return false;
}

void SettingFilterMap::filterRead(string& value)
{
    if(m_filterMap.empty())
        return;

    map<string, string>::const_iterator itMapping = m_filterMap.find(value);
    if(itMapping != m_filterMap.end())
        value = itMapping->second;
}

SettingFilterMin::SettingFilterMin(int min)
    : m_min(min)
{
}

SettingFilterMin::~SettingFilterMin()
{
}

string SettingFilterMin::getId() const
{
    return "min";
}

void SettingFilterMin::setMin(int min)
{
    m_min = min;
}

int SettingFilterMin::getMin() const
{
    return m_min;
}

bool SettingFilterMin::filterWrite(string& valueNew)
{
    if(fromString<int>(valueNew) < m_min)
        valueNew = toString(m_min);

    return true;
}

void SettingFilterMin::filterRead(string& value)
{
}

SettingFilterMax::SettingFilterMax(int max)
    : m_max(max)
{
}

SettingFilterMax::~SettingFilterMax()
{
}

string SettingFilterMax::getId() const
{
    return "max";
}

void SettingFilterMax::setMax(int max)
{
    m_max = max;
}

int SettingFilterMax::getMax() const
{
    return m_max;
}

bool SettingFilterMax::filterWrite(string& valueNew)
{
    if(fromString<int>(valueNew) > m_max)
        valueNew = toString(m_max);

    return true;
}

void SettingFilterMax::filterRead(string& value)
{
}
