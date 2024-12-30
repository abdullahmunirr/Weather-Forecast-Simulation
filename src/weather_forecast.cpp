#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class WeatherForecast
{
private:
    string location;
    int day;
    string season;
    int *dayTemp;
    int *nightTemp;
    string *condition;
    int *windSpeed;
    string *windDirection;
    
    int getRandomNumber(int low, int high)
    {
        return rand() % (high - low + 1) + low;
    }
    
    string getRandomCondition()
    {
        string allConditions[] =
        {"Sunny", "Cloudy", "Rainy", "Snowy", "Stormy", "Foggy"};
        return allConditions[getRandomNumber(0, 5)];
    }
    
    string getRandomWindDirection()
    {
        string directions[] = {"N","E","S", "NE","SE","SW","W","NW"};
        return directions[getRandomNumber(0, 7)];
    }
    
public:
    WeatherForecast()
    {
        day = 7;
        location = "Current City";
        season = "Summer";
        dayTemp = nullptr;
        nightTemp = nullptr;
        condition = nullptr;
        windSpeed = nullptr;
        windDirection = nullptr;
    }
    
    ~WeatherForecast()
    {
        delete[] dayTemp;
        delete[] nightTemp;
        delete[] condition;
        delete[] windSpeed;
        delete[] windDirection;
    }
    
    void setLocation(const string &l)
    {
        location = l;
    }
    
    void setDays(int d)
    {
        day = d;
    }
    
    void setSeason(const string &s)
    {
        season = s;
    }
    
    void generateForecast()
    {
        dayTemp = new int[day];
        nightTemp = new int[day];
        condition = new string[day];
        windSpeed = new int[day];
        windDirection = new string[day];
        
        int tempLow = 0;
        int tempHigh = 0;
        
        if (season == "Summer")
        {
            tempLow = 20;
            tempHigh = 40;
        }
        
        else if (season == "Winter")
        {
            tempLow = -10;
            tempHigh = 10;
        }
        
        else if (season == "Spring")
        {
            tempLow = 10;
            tempHigh = 25;
        }
        
        else if (season == "Autumn")
        {
            tempLow = 15;
            tempHigh = 30;
        }
        
        for (int i = 0; i < day; i++)
        {
            dayTemp[i] = getRandomNumber(tempLow, tempHigh);
            nightTemp[i] = getRandomNumber(tempLow - 5, tempHigh - 5);
            condition[i] = getRandomCondition();
            windSpeed[i] = getRandomNumber(5, 20);
            windDirection[i] = getRandomWindDirection();
        }
    }
    
    void displayForecast()
    {
        cout << endl << "--- Weather Forecast for "
        << location << " ---" << endl;
        
        cout << "Season: " << season << endl << endl;
        cout << "Day | Day Temp | Night Temp | Direction | Wind | Condition" << endl;
        
        for (int i = 0; i < day; i++)
        {
            cout << "Day " << i + 1 << " | ";
            cout << dayTemp[i] << "°C      | ";
            cout << nightTemp[i] << "°C       | ";
            cout << windSpeed[i] << "       | ";
            cout << windDirection[i] << "   |";
            cout << condition[i] << endl;
        }
    }
    
    void showTempratureGraph()
    {
        cout << endl << "--- Temperature Trend ---" << endl;
        for (int i = 0; i < day; i++)
        {
            cout << "Day " << i + 1 << ": ";
            for (int j = 0; j < dayTemp[i]; j += 2)
            {
                cout << "|";
            }
            cout << " (" << dayTemp[i] << "°C)" << endl;
        }
    }
    
    void showStatistics()
    {
        int sumDay = 0;
        int sumNight = 0;
        int maxTemp = INT_MIN;
        int minTemp = INT_MAX;
        
        for (int i = 0; i < day; i++)
        {
            sumDay += dayTemp[i];
            sumNight += nightTemp[i];
            maxTemp = max(maxTemp, dayTemp[i]);
            minTemp = min(minTemp, dayTemp[i]);
        }
        
        cout << endl << "--- Weather Statistics ---" << endl;
        cout << "Average Day Temperature: " << (sumDay / day)
        << "°C" << endl;
        cout << "Average Night Temperature: " << (sumNight / day)
        << "°C" << endl;
        cout << "Highest Temperature: " << maxTemp << "°C" << endl;
        cout << "Lowest Temperature: " << minTemp << "°C" << endl;
    }
    
    void saveToFile(const string &filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Data can't be saved" << endl;
            return;
        }
        
        file << location << endl << season << endl << day << endl;
        
        for (int i = 0; i < day; i++)
        {
            file << dayTemp[i] << " " << nightTemp[i] << " " << condition[i] << " " << windSpeed[i] << " " << windDirection[i] << endl;
        }
        
        file.close();
        cout << "Forecast saved to file: " << filename << endl;
    }
    
    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Data cant be loaded" << endl;
            return;
        }
        
        file >> location >> season >> day;
        
        delete[] dayTemp;
        delete[] nightTemp;
        delete[] condition;
        delete[] windSpeed;
        delete[] windDirection;
        
        dayTemp = new int[day];
        nightTemp = new int[day];
        condition = new string[day];
        windSpeed = new int[day];
        windDirection = new string[day];
        
        for (int i = 0; i < day; i++)
        {
            file >> dayTemp[i] >> nightTemp[i] >> condition[i] >> windSpeed[i] >> windDirection[i];
        }
        
        file.close();
        cout << "Forecast loaded from file: " << filename << endl;
    }
};


int main ()
{
    srand(time(0));
    
    WeatherForecast wf;
    wf.setLocation("Lahore");
    wf.setDays(7);
    wf.setSeason("Summer");
    wf.generateForecast();
    wf.displayForecast();
    wf.showTempratureGraph();
    wf.showStatistics();
    wf.saveToFile("forecast.txt");
    wf.loadFromFile("forecast.txt");
    
    return 0;
}
