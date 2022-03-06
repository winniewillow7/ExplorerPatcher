#ifndef _H_EP_WEATHER_PROVIDER_GOOGLE_SCRIPT_H_
#define _H_EP_WEATHER_PROVIDER_GOOGLE_SCRIPT_H_
#include <Windows.h>
// many thanks to https://stackoverflow.com/questions/23202966/google-weather-widget-on-my-website
#define EP_WEATHER_PROVIDER_GOOGLE_SCRIPT_LEN 20000

LPCWSTR ep_weather_provider_google_script10 = L"var final_im = 0; function ep_weather_part0() { return \"run_part_0\"; }; ep_weather_part0();";

// reference: https://github.com/Triggertrap/sun-js
LPCWSTR ep_weather_provider_google_script00 = L"\
Date.prototype.sunrise = function(latitude, longitude, zenith) {\n\
	return this.sunriseSet(latitude, longitude, true, zenith);\n\
}\n\
Date.prototype.sunset = function(latitude, longitude, zenith) {\n\
	return this.sunriseSet(latitude, longitude, false, zenith);\n\
}\n\
Date.prototype.sunriseSet = function(latitude, longitude, sunrise, zenith) {\n\
	if(!zenith) {\n\
		zenith = 90.8333;\n\
	}\n\
	var hoursFromMeridian = longitude / Date.DEGREES_PER_HOUR,\n\
		dayOfYear = this.getDayOfYear(),\n\
		approxTimeOfEventInDays,\n\
		sunMeanAnomaly,\n\
		sunTrueLongitude,\n\
		ascension,\n\
		rightAscension,\n\
		lQuadrant,\n\
		raQuadrant,\n\
		sinDec,\n\
		cosDec,\n\
		localHourAngle,\n\
		localHour,\n\
		localMeanTime,\n\
		time;\n\
	if (sunrise) {\n\
        approxTimeOfEventInDays = dayOfYear + ((6 - hoursFromMeridian) / 24);\n\
    } else {\n\
        approxTimeOfEventInDays = dayOfYear + ((18.0 - hoursFromMeridian) / 24);\n\
    }\n\
	sunMeanAnomaly = (0.9856 * approxTimeOfEventInDays) - 3.289;\n\
	sunTrueLongitude = sunMeanAnomaly + (1.916 * Math.sinDeg(sunMeanAnomaly)) + (0.020 * Math.sinDeg(2 * sunMeanAnomaly)) + 282.634;\n\
	sunTrueLongitude =  Math.mod(sunTrueLongitude, 360);\n\
	ascension = 0.91764 * Math.tanDeg(sunTrueLongitude);\n\
    rightAscension = 360 / (2 * Math.PI) * Math.atan(ascension);\n\
    rightAscension = Math.mod(rightAscension, 360);\n\
    lQuadrant = Math.floor(sunTrueLongitude / 90) * 90;\n\
    raQuadrant = Math.floor(rightAscension / 90) * 90;\n\
    rightAscension = rightAscension + (lQuadrant - raQuadrant);\n\
    rightAscension /= Date.DEGREES_PER_HOUR;\n\
    sinDec = 0.39782 * Math.sinDeg(sunTrueLongitude);\n\
	cosDec = Math.cosDeg(Math.asinDeg(sinDec));\n\
	cosLocalHourAngle = ((Math.cosDeg(zenith)) - (sinDec * (Math.sinDeg(latitude)))) / (cosDec * (Math.cosDeg(latitude)));\n\
	localHourAngle = Math.acosDeg(cosLocalHourAngle)\n\
	if (sunrise) {\n\
		localHourAngle = 360 - localHourAngle;\n\
	}\n\
	localHour = localHourAngle / Date.DEGREES_PER_HOUR;\n\
	localMeanTime = localHour + rightAscension - (0.06571 * approxTimeOfEventInDays) - 6.622;\n\
	time = localMeanTime - (longitude / Date.DEGREES_PER_HOUR);\n\
	time = Math.mod(time, 24);\n\
	var midnight = new Date(0);\n\
		midnight.setUTCFullYear(this.getUTCFullYear());\n\
		midnight.setUTCMonth(this.getUTCMonth());\n\
		midnight.setUTCDate(this.getUTCDate());\n\
	var milli = midnight.getTime() + (time * 60 *60 * 1000);\n\
	return new Date(milli);\n\
}\n\
Date.DEGREES_PER_HOUR = 360 / 24;\n\
Date.prototype.getDayOfYear = function() {\n\
	var onejan = new Date(this.getFullYear(),0,1);\n\
	return Math.ceil((this - onejan) / 86400000);\n\
}\n\
Math.degToRad = function(num) {\n\
	return num * Math.PI / 180;\n\
}\n\
Math.radToDeg = function(radians){\n\
    return radians * 180.0 / Math.PI;\n\
}\n\
Math.sinDeg = function(deg) {\n\
    return Math.sin(deg * 2.0 * Math.PI / 360.0);\n\
}\n\
Math.acosDeg = function(x) {\n\
    return Math.acos(x) * 360.0 / (2 * Math.PI);\n\
}\n\
Math.asinDeg = function(x) {\n\
    return Math.asin(x) * 360.0 / (2 * Math.PI);\n\
}\n\
Math.tanDeg = function(deg) {\n\
    return Math.tan(deg * 2.0 * Math.PI / 360.0);\n\
}\n\
Math.cosDeg = function(deg) {\n\
    return Math.cos(deg * 2.0 * Math.PI / 360.0);\n\
}\n\
Math.mod = function(a, b) {\n\
	var result = a % b;\n\
	if(result < 0) {\n\
		result += b;\n\
	}\n\
	return result;\n\
}\n\
\n\
\n\
var final_im = 0;\n\
var final_img = 0;\n\
var final_int;\n\
var final_cnt = 0;\n\
function ep_set_final_img(){\n\
document.getElementById('wob_tci').src = final_img;\n\
final_cnt++;\n\
if (final_cnt == 20) clearInterval(final_int);\n\
}\n\
function ep_download_image_blob(url) {\n\
    var request = new XMLHttpRequest();\n\
    request.open('GET', url, false);\n\
    request.overrideMimeType('text/plain; charset=x-user-defined');\n\
    request.send(null);\n\
    var binary = new Uint8Array(request.responseText.length);\n\
    for(var i=0;i<request.responseText.length;i++){ binary[i] = request.responseText.charCodeAt(i) & 0xff; }\n\
    return URL.createObjectURL(new Blob([binary.buffer]));\n\
}\n\
var w_url = document.querySelector('.YfftMc').childNodes[0].href;\n\
var lat = 0.0;\n\
var lon = 0.0;\n\
if (w_url.includes('weathernews.jp')) {\n\
lat = parseFloat(w_url.split('/')[4]);\n\
lon = parseFloat(w_url.split('/')[5]);\n\
} else {\n\
var urlParams = new URLSearchParams(w_url);\n\
lat = parseFloat(urlParams.get('https://www.weather.com/wx/today/?lat'));\n\
lon = parseFloat(urlParams.get('lon'));\n\
}\n\
var current = new Date();\n\
current.setSeconds(0);\n\
current.setMilliseconds(0);\n\
var sunrise = new Date().sunrise(lat, lon);\n\
sunrise.setFullYear(current.getFullYear());\n\
sunrise.setMonth(current.getMonth());\n\
sunrise.setDate(current.getDate());\n\
sunrise.setSeconds(0);\n\
sunrise.setMilliseconds(0);\n\
var sunset = new Date().sunset(lat, lon);\n\
sunset.setFullYear(current.getFullYear());\n\
sunset.setMonth(current.getMonth());\n\
sunset.setDate(current.getDate());\n\
sunset.setSeconds(0);\n\
sunset.setMilliseconds(0);\n\
var is_day = 0;\n\
console.log(sunrise);\n\
console.log(sunset);\n\
console.log(current);\n\
while (1) {\n\
if (sunrise.getTime() == current.getTime()) { is_day = 1; break; }\n\
if (sunrise.getHours() == 23 && sunrise.getMinutes() == 59) { sunrise.setHours(0); sunrise.setMinutes(0); }\n\
else if (sunrise.getMinutes() == 59) { sunrise.setHours(sunrise.getHours() + 1); sunrise.setMinutes(0); }\n\
else sunrise.setMinutes(sunrise.getMinutes() + 1);\n\
if (sunrise.getTime() == sunset.getTime()) break;\n\
}\n\
console.log(is_day);\n\
";

LPCWSTR ep_weather_provider_google_script01 = L"\
var im = document.getElementById('wob_tci');\n\
if (im.src.endsWith('64/sunny_s_cloudy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908235-1f97c25b-3561-485b-b7fb-bf926ef1208c.png');\n\
    else final_img =        ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908236-6e86fcb1-3fd4-41ff-bee6-006f01057c16.png');\n\
} else if (im.src.endsWith('64/sunny.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908219-cf8c0c60-c37d-44b4-b266-c7ee5e8bd551.png');\n\
    else final_img =        ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908221-ad8c1d1d-0e26-4831-b7a7-3903d9fcc913.png');\n\
} else if (im.src.endsWith('64/cloudy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908223-4a29a001-b0dc-487f-af2f-4da5c9fc5bc6.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908223-4a29a001-b0dc-487f-af2f-4da5c9fc5bc6.png');\n\
} else if (im.src.endsWith('64/rain_s_cloudy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
} else if (im.src.endsWith('64/cloudy_s_rain.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
} else if (im.src.endsWith('64/rain_light.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908227-3d0b307c-8fff-42cb-8f40-b3ab3cf40d1d.png');\n\
} else if (im.src.endsWith('64/rain.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908229-509c4431-1e12-4e55-a00d-586a77a36eb4.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908229-509c4431-1e12-4e55-a00d-586a77a36eb4.png');\n\
} else if (im.src.endsWith('64/rain_heavy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908229-509c4431-1e12-4e55-a00d-586a77a36eb4.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908229-509c4431-1e12-4e55-a00d-586a77a36eb4.png');\n\
} else if (im.src.endsWith('64/thunderstorms.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908220-1561869e-1bfa-4dec-97e9-006da24672c1.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908220-1561869e-1bfa-4dec-97e9-006da24672c1.png');\n\
} else if (im.src.endsWith('64/cloudy_s_sunny.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908231-0f708bb5-a757-47ff-86f2-ff90fac00031.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908232-a3595fef-b6b2-411a-b0a6-b837a0932753.png');\n\
} else if (im.src.endsWith('64/partly_cloudy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908234-413c1bf8-969b-4add-8c28-b1db261b0d57.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908230-7d9ffa4c-468b-458c-ae4f-d3b26a7f7a02.png');\n\
} else if (im.src.endsWith('64/sunny_s_rain.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908214-0b245044-6d75-488b-8469-4671fb75d351.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908215-29f5d60e-bf47-466b-9b60-f19a78f3038b.png');\n\
} else if (im.src.endsWith('64/rain_s_sunny.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908217-38f9ea12-c5b8-4f35-9003-b01e9aa3df68.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908218-81799162-052c-4624-a22d-28f772144ff8.png');\n\
} else if (im.src.endsWith('64/fog.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908225-9099c899-8d43-492c-a672-b99a666b1f1b.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908225-9099c899-8d43-492c-a672-b99a666b1f1b.png');\n\
} else if (im.src.endsWith('64/snow.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908228-a02fc908-0f1a-4978-af3e-47ecaaacc5a5.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908228-a02fc908-0f1a-4978-af3e-47ecaaacc5a5.png');\n\
} else if (im.src.endsWith('64/snow_heavy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908226-186d9998-2e98-48fb-8ca9-5393831bbec9.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908226-186d9998-2e98-48fb-8ca9-5393831bbec9.png');\n\
} else if (im.src.endsWith('64/snow_light.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908228-a02fc908-0f1a-4978-af3e-47ecaaacc5a5.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908228-a02fc908-0f1a-4978-af3e-47ecaaacc5a5.png');\n\
} else if (im.src.endsWith('64/snow_s_cloudy.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908217-38f9ea12-c5b8-4f35-9003-b01e9aa3df68.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908218-81799162-052c-4624-a22d-28f772144ff8.png');\n\
} else if (im.src.endsWith('64/snow_s_rain.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908216-b68edf4b-1355-4889-b3ac-216cf2210457.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908216-b68edf4b-1355-4889-b3ac-216cf2210457.png');\n\
} else if (im.src.endsWith('64/cloudy_s_snow.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908217-38f9ea12-c5b8-4f35-9003-b01e9aa3df68.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908218-81799162-052c-4624-a22d-28f772144ff8.png');\n\
} else if (im.src.endsWith('64/rain_s_snow.png')) {\n\
    if (is_day) final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908216-b68edf4b-1355-4889-b3ac-216cf2210457.png');\n\
    else        final_img = ep_download_image_blob('https://user-images.githubusercontent.com/6503598/156908216-b68edf4b-1355-4889-b3ac-216cf2210457.png');\n\
}\n\
if (final_img != 0) { final_im = new Image(); final_im.src = final_img; }\n\
//if (final_img != 0) {\n\
//final_int = setInterval(ep_set_final_img, 500);\n\
//document.getElementById('wob_tci').src = final_img;\n\
//}\n\
function ep_weather_part0() {\n\
return \"run_part_0\";\n\
}\n\
ep_weather_part0();\n\
";

LPCWSTR ep_weather_provider_google_script = L"\
function changeCSSStyle(ssMain, selector, cssProp, cssVal) {\n\
var cssRules = (document.all) ? 'rules': 'cssRules'; \n\
//console.log(ssMain);\n\
  for (i=0, len=document.styleSheets[ssMain][cssRules].length; i<len; i++)\n\
  {\n\
    if (document.styleSheets[ssMain][cssRules][i].selectorText === selector) {\n\
      document.styleSheets[ssMain][cssRules][i].style[cssProp] = cssVal; \n\
//console.log('DA');\n\
      return; \n\
    }\n\
  }\n\
}\n\
function ep_weather_utf8ToHex(str) {\n\
  return Array.from(str).map(c => \n\
    c.charCodeAt(0) < 128 ? c.charCodeAt(0).toString(16) : \n\
    encodeURIComponent(c).replace(/\\%%/g,'').toLowerCase()\n\
  ).join('');\n\
}\n\
function ep_weather_drawImageToCanvas(image) {\n\
  const canvas = document.createElement('canvas');\n\
  const w = image.width;\n\
  const h = image.height;\n\
  canvas.width = w;\n\
  canvas.height = h;\n\
  canvas.getContext('2d').drawImage(image, 0, 0);\n\
  return canvas;\n\
}\n\
function ep_weather_toHexString (byteArray) {\n\
  //const chars = new Buffer(byteArray.length * 2);\n\
  const chars = new Uint8Array(byteArray.length * 2);\n\
  const alpha = 'a'.charCodeAt(0) - 10;\n\
  const digit = '0'.charCodeAt(0);\n\
  \n\
  let p = 0;\n\
  for (let i = 0; i < byteArray.length; i++) {\n\
      let nibble = byteArray[i] >>> 4;\n\
      chars[p++] = nibble > 9 ? nibble + alpha : nibble + digit;\n\
      nibble = byteArray[i] & 0xF;\n\
      chars[p++] = nibble > 9 ? nibble + alpha : nibble + digit;\n\
  }\n\
  \n\
  //return chars.toString('utf8');\n\
  return String.fromCharCode.apply(null, chars);\n\
}\n\
function ep_weather_getData(imageBitmap, ch) {\n\
  const canvas = ep_weather_drawImageToCanvas(imageBitmap);\n\
  const ctx = canvas.getContext('2d');\n\
  \n\
  let result = [];\n\
  for (let y = 0; y < canvas.height; y++) {\n\
    for (let x = 0; x < canvas.width; x++) {\n\
      let data = ctx.getImageData(x, y, 1, 1).data;\n\
      result.push(data[2] * data[3] / 255);\n\
      result.push(data[1] * data[3] / 255);\n\
      result.push(data[0] * data[3] / 255);\n\
      result.push(data[3]);\n\
    }\n\
  }\n\
  let res = (\n\
    document.documentElement.getAttribute(\"dir\") + \"#\" + \n\
    document.getElementsByClassName(\"ULSxyf\")[0].offsetHeight + \"#\" + \n\
    document.getElementById(ch.includes('x') ? \"wob_ttm\" : \"wob_tm\").innerText + \"#\" + \n\
    Array.from(document.getElementsByClassName('wob-unit')[0].getElementsByTagName('span')).filter(e => e.className == 'wob_t').filter(e => !e.style.display.toString().includes(\"none\"))[0].innerText + \"#\" + \n\
    document.getElementById(\"wob_tci\").alt + \"#\" + \n\
    document.getElementById(\"wob_loc\").innerText + \"#\" + \n\
    ep_weather_toHexString(result)\n\
  );\n\
  //console.log(res);\n\
  document.body.style.backgroundColor='transparent';\n\
  document.body.style.backgroundColor='transparent';\n\
  return res;\n\
}\n\
var ep_result;\n\
let unit = Array.from(document.getElementsByClassName('wob-unit')[0].getElementsByTagName('span')).filter(e => e.className == 'wob_t')[0].innerText;\n\
let p = '%c';\n\
if (!unit.includes(p)) {\n\
    Array.from(document.getElementsByClassName('wob-unit')[0].getElementsByTagName('a')).filter(e => e.className == 'wob_t').filter(e => e.innerText.includes(p))[0].click();\n\
    unit = 'x';\n\
}\n\
createImageBitmap(\n\
    (final_im != 0) ? final_im : document.getElementById('wob_tci'), \n\
    { resizeWidth: %d, resizeHeight: %d, resizeQuality: 'high' }\n\
)\n\
.then(imageBitmap => \n\
    ep_result = ep_weather_getData(imageBitmap, unit)\n\
);\n\
function ep_weather_part1() {\n\
return \"run_part_2\";\n\
}\n\
ep_weather_part1();\n\
";

LPCWSTR ep_weather_provider_google_script2 = L"\
function scrolldisable() {\n\
TopScroll = window.pageYOffset || document.documentElement.scrollTop;\n\
LeftScroll = window.pageXOffset || document.documentElement.scrollLeft;\n\
window.onscroll = function() {\n\
window.scrollTo(LeftScroll, TopScroll);\n\
        };\n\
}\n\
function ep_weather_part2() {\n\
let h = document.getElementsByClassName(\"ULSxyf\")[0].offsetHeight;\n\
////document.getElementsByClassName(\"google-weather-place\")[0].style.height = h + 'px';\n\
////document.getElementsByClassName(\"google-weather-crop\")[0].style.height = h + 'px';\n\
//if (1) for (let j = 0; j < document.styleSheets.length; j++) changeCSSStyle(j, '.wob_ds', 'background-color', '#303134');\n\
document.getElementsByClassName(\"KFFQ0c\")[0].style.display = 'none';\n\
if (document.getElementsByClassName(\"QS5gu sy4vM\").length > 1) { document.getElementsByClassName(\"QS5gu sy4vM\")[1].click(); return \"run_part_1\"; }\n\
if (document.getElementsByClassName(\"Gfzyee VDgVie DKlyaf Loxgyb\").length > 1) { document.getElementsByClassName(\"Gfzyee VDgVie DKlyaf Loxgyb\")[1].click(); return \"run_part_1\"; }\n\
//document.getElementById(\"search\").scrollIntoView(true);\n\
return ep_result;\n\
}\n\
let banner1 = document.getElementById(\"taw\"); if (banner1) { banner1.style = \"display: none\"; }\n\
let wob_gsp = document.getElementById(\"wob_gsp\"); if (wob_gsp) { wob_gsp.style = \"width: 648.04px\"; }\n\
scrolldisable();\n\
ep_weather_part2();\n\
";
#endif