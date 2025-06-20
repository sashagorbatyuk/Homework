const apiKey = '42b9e2c1d3ec4f171c24098cdaddcebe';
let currentCity = '';

async function fetchWeather(city) {
    try {
        const res = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`);
        if (!res.ok) throw new Error();
        const data = await res.json();
        currentCity = data.name;
        document.getElementById('cityInput').value = currentCity;
        document.getElementById('error').classList.remove('active');
        document.querySelector('.tab-content.active').classList.remove('active');
        document.getElementById('today').classList.add('active');
        renderToday(data);
        fetchHourlyAndForecast(city);
    } catch {
        document.querySelector('.tab-content.active').classList.remove('active');
        document.getElementById('error').classList.add('active');
    }
}

async function fetchHourlyAndForecast(city) {
    const res = await fetch(`https://api.openweathermap.org/data/2.5/forecast?q=${city}&appid=${apiKey}&units=metric`);
    const data = await res.json();
    renderHourly(data);
    renderForecast(data);
}

function renderToday(data) {
    const sunrise = new Date(data.sys.sunrise * 1000);
    const sunset = new Date(data.sys.sunset * 1000);
    const duration = (sunset - sunrise) / 3600000;

    document.getElementById('today-summary').innerHTML = `
        <h2>${new Date().toDateString()}</h2>
        <p><img src="https://openweathermap.org/img/wn/${data.weather[0].icon}@2x.png"> ${data.weather[0].description}</p>
        <p>Temp: ${data.main.temp} °C (Feels like: ${data.main.feels_like} °C)</p>
        <p>Sunrise: ${sunrise.toLocaleTimeString()} | Sunset: ${sunset.toLocaleTimeString()} | Duration: ${duration.toFixed(1)}h</p>
    `;
}

function renderHourly(data) {
    const now = new Date();
    const html = data.list.filter(item => new Date(item.dt_txt) > now && new Date(item.dt_txt).getHours() % 3 === 0)
        .slice(0, 8).map(item => `
        <div>
            <strong>${new Date(item.dt_txt).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</strong> -
            <img src="https://openweathermap.org/img/wn/${item.weather[0].icon}.png">
            ${item.weather[0].description},
            ${item.main.temp} °C (Feels like ${item.main.feels_like} °C),
            Wind: ${item.wind.speed} km/h
        </div>`).join('');
    document.getElementById('today-hourly').innerHTML = html;
}

function renderForecast(data) {
    const daysMap = {};
    data.list.forEach(item => {
        const date = item.dt_txt.split(' ')[0];
        if (!daysMap[date]) daysMap[date] = [];
        daysMap[date].push(item);
    });

    const dates = Object.keys(daysMap).slice(0, 5);
    const forecastDays = document.getElementById('forecast-days');
    forecastDays.innerHTML = '';

    dates.forEach((date, idx) => {
        const dayData = daysMap[date][0];
        const div = document.createElement('div');
        div.innerHTML = `${new Date(date).toDateString()}<br><img src="https://openweathermap.org/img/wn/${dayData.weather[0].icon}.png"> ${dayData.main.temp} °C - ${dayData.weather[0].description}`;
        div.onclick = () => renderForecastHourly(daysMap[date], div);
        if (idx === 0) renderForecastHourly(daysMap[date], div);
        forecastDays.appendChild(div);
    });
}

function renderForecastHourly(items, selectedDiv) {
    document.querySelectorAll('#forecast-days > div').forEach(div => div.classList.remove('selected'));
    selectedDiv.classList.add('selected');
    const html = items.map(item => `
        <div>
            <strong>${new Date(item.dt_txt).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</strong> -
            <img src="https://openweathermap.org/img/wn/${item.weather[0].icon}.png">
            ${item.weather[0].description},
            ${item.main.temp} °C (Feels like ${item.main.feels_like} °C),
            Wind: ${item.wind.speed} km/h
        </div>`).join('');
    document.getElementById('forecast-hourly').innerHTML = html;
}

document.getElementById('searchBtn').onclick = () => {
    const city = document.getElementById('cityInput').value;
    if (city) fetchWeather(city);
};

document.querySelectorAll('.tab-button').forEach(btn => {
    btn.onclick = () => {
        document.querySelectorAll('.tab-button').forEach(b => b.classList.remove('active'));
        btn.classList.add('active');
        document.querySelectorAll('.tab-content').forEach(tab => tab.classList.remove('active'));
        document.getElementById(btn.dataset.tab).classList.add('active');
    };
});

// Try geolocation
if (navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(async pos => {
        const { latitude, longitude } = pos.coords;
        const res = await fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${apiKey}&units=metric`);
        const data = await res.json();
        fetchWeather(data.name);
    }, () => fetchWeather('Kyiv'));
} else {
    fetchWeather('Kyiv');
}
