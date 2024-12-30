# **Weather Forecast Simulation**

**Description**  
A command-line weather forecasting simulation built in C++. This program generates and displays a week-long weather forecast for a specified location and season. The forecast includes day and night temperatures, weather conditions, wind speed, and direction. It also provides visualizations and statistical analysis of the data.

---

## **Table of Contents**

1. [Features](#features)  
2. [How It Works](#how-it-works)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements)

---

## **Features**

### **1. Weather Forecast Generation**
- Generates a 7-day weather forecast for a specified location and season.  
- Includes day and night temperatures, weather conditions, wind speed, and direction.  

### **2. Data Visualization**
- **Temperature Trend Graph**: Displays a visual representation of temperature variations over the week.  
- **Weather Statistics**: Calculates and displays average, maximum, and minimum temperatures for the forecast period.  

### **3. File Management**
- **Save Forecast**: Exports the generated forecast to a file for record-keeping.  
- **Load Forecast**: Loads a previously saved forecast from a file.  

### **4. User-Friendly Features**
- Set custom location, season, and number of days for the forecast.  
- Automatically generates random weather data based on the selected season.  

---

## **How It Works**

1. **Data Generation**:  
   - Based on the selected season, random temperatures, weather conditions, and wind data are generated.  
   - Seasons affect the temperature range:
     - **Summer**: 20°C to 40°C  
     - **Winter**: -10°C to 10°C  
     - **Spring**: 10°C to 25°C  
     - **Autumn**: 15°C to 30°C  

2. **Forecast Display**:  
   - Displays the day-by-day weather forecast, including:
     - Day and night temperatures.  
     - Wind speed and direction.  
     - Weather conditions (e.g., Sunny, Rainy, Cloudy).  

3. **Visualization and Statistics**:  
   - Visualize temperature trends over the week using a simple bar graph.  
   - Compute and display statistics like average, maximum, and minimum temperatures.  

4. **File Management**:  
   - Save the forecast to a file (`forecast.txt`) for future use.  
   - Load saved forecasts for review or analysis.  

---

## **Installation**

Follow these steps to set up and run the Weather Forecast Simulation locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd WeatherForecastSimulation
   ```

2. Compile the program:
   ```bash
   g++ -o weather_forecast weather_forecast.cpp
   ```

3. Run the program:
   ```bash
   ./weather_forecast
   ```

---

## **Example Output**

```plaintext
--- Weather Forecast for Lahore ---
Season: Summer

Day   | Day Temp  | Night Temp | Direction | Wind     | Condition
Day 1 | 35°C      | 30°C       | N         | 15       | Sunny
Day 2 | 32°C      | 28°C       | NW        | 12       | Cloudy
Day 3 | 37°C      | 33°C       | SE        | 18       | Rainy
...

--- Temperature Trend ---
Day 1: |||||||||||||||||||||||||||||||||||||| (35°C)
Day 2: |||||||||||||||||||||||||||||||||||| (32°C)
...

--- Weather Statistics ---
Average Day Temperature: 34°C
Average Night Temperature: 29°C
Highest Temperature: 37°C
Lowest Temperature: 30°C
```

---

## **Technologies Used**

- **Language**: C++  
- **Libraries**: `<iostream>`, `<fstream>`, `<cstdlib>`, `<ctime>`  

---

## **Future Enhancements**

- Add more detailed weather conditions (e.g., humidity, visibility).  
- Support forecasts for multiple locations simultaneously.  
- Introduce real-time weather data fetching using APIs.  
- Extend the temperature graph with more advanced visualizations.  
- Add graphical user interface (GUI) support.
