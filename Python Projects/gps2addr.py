from geopy.extra.rate_limiter import RateLimiter
from geopy.geocoders import Nominatim
import pandas as pd
from tqdm import tqdm

tqdm.pandas()
locator = Nominatim(user_agent='myGeocoder', timeout=10)
reverse_geocode = RateLimiter(locator.reverse, min_delay_seconds=0.01)

filename = input('Input the Excel filename: ')
if '.xlsx' not in filename:
    filename = filename + '.xlsx'
df1 = pd.read_excel(filename)

df1['coordinates'] = df1['Lat'].map(str) + ', ' + df1['Long'].map(str)

df1['address'] = df1['coordinates'].progress_apply(reverse_geocode)

df1.to_excel('output.xlsx')
