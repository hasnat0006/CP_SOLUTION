import requests
from bs4 import BeautifulSoup
import pandas as pd
import re
import csv

def fetch_codeforces_organization_data(org_id):
    """
    Fetch user data from Codeforces organization ratings page
    """
    url = f"https://codeforces.com/ratings/organization/{org_id}"
    
    print(f"Fetching data from: {url}")
    
    # Send GET request with headers to mimic a browser
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    
    try:
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        
        # Parse the HTML content
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Find the ratings table
        users_data = []
        
        # Look for table rows containing user data
        # The data appears to be in a table format based on the fetched content
        table_rows = soup.find_all('tr')
        
        for row in table_rows:
            cells = row.find_all('td')
            if len(cells) >= 4:  # Expecting at least 4 columns: rank, country/username, contests, rating
                try:
                    # Extract data from cells
                    rank_cell = cells[0].get_text(strip=True)
                    user_info_cell = cells[1].get_text(strip=True)
                    contests_cell = cells[2].get_text(strip=True)
                    rating_cell = cells[3].get_text(strip=True)
                    
                    # Parse rank (remove parentheses if present)
                    rank_match = re.search(r'\d+', rank_cell)
                    if rank_match:
                        rank = rank_match.group()
                    else:
                        continue
                    
                    # Parse user info (country and username)
                    # Split by spaces and identify country and username
                    parts = user_info_cell.split()
                    if len(parts) >= 2:
                        if 'Bangladesh' in user_info_cell:
                            country = 'Bangladesh'
                            username = user_info_cell.replace('Bangladesh', '').strip()
                        else:
                            # If no explicit country, assume the first part is country if it's not a username pattern
                            if len(parts) == 1:
                                country = 'Unknown'
                                username = parts[0]
                            else:
                                country = parts[0] if not parts[0].islower() else 'Unknown'
                                username = ' '.join(parts[1:]) if country != 'Unknown' else ' '.join(parts)
                    else:
                        country = 'Unknown'
                        username = user_info_cell
                    
                    # Parse contests and rating
                    try:
                        contests = int(contests_cell)
                        rating = int(rating_cell)
                    except ValueError:
                        continue
                    
                    users_data.append({
                        'Rank': rank,
                        'Country': country,
                        'Username': username,
                        'Contests': contests,
                        'Rating': rating
                    })
                    
                except Exception as e:
                    continue
        
        return users_data
        
    except requests.RequestException as e:
        print(f"Error fetching data: {e}")
        return []

def parse_manual_data():
    """
    Parse the data manually from the fetched content since web scraping might be limited
    """
    # Data extracted from the webpage content
    manual_data = [
        (15687, 'Bangladesh', 'mnzb2000', 259, 1532),
        (16756, 'Bangladesh', 'trqrizu', 208, 1511),
        (21171, 'Bangladesh', 'Zarif_Mustafa', 169, 1442),
        (27348, 'Bangladesh', 'Nasif273', 96, 1364),
        (28542, 'Bangladesh', 'Hasnat0006', 175, 1348),
        (28964, 'Bangladesh', 'Rafsan18', 68, 1343),
        (30714, 'Bangladesh', 'Ariful101', 50, 1323),
        (30879, 'Bangladesh', 'sabbir_063', 94, 1321),
        (31155, 'Bangladesh', 'Ahmad_Abdullah', 160, 1318),
        (31332, 'Bangladesh', 'Syeda_Raisa_Rahman', 128, 1316),
        (32108, 'Bangladesh', 'Pallab827', 85, 1308),
        (32290, 'Bangladesh', 'Farhan_Nasif_Nizami', 144, 1306),
        (34936, 'Unknown', 'Saif_Ahmed008', 120, 1278),
        (35027, 'Bangladesh', 'meem_358', 90, 1277),
        (35550, 'Bangladesh', 'SADIQ_insD', 154, 1272),
        (37901, 'Bangladesh', 'Istiaque_ahmed', 175, 1250),
        (38025, 'Unknown', 'buchu', 70, 1249),
        (40111, 'Bangladesh', 'Maria_Sultana', 151, 1231),
        (41259, 'Bangladesh', '_Shir0_', 72, 1222),
        (42657, 'Bangladesh', 'tamal_63', 139, 1211),
        (45830, 'Bangladesh', 'miraz3301', 15, 1183),
        (50704, 'Bangladesh', 'Ragib100', 79, 1141),
        (52057, 'Bangladesh', 'arafat03', 85, 1130),
        (53199, 'Bangladesh', 'raisul_rahad', 80, 1121),
        (53308, 'Unknown', 'Arif_Sadik', 36, 1120),
        (55846, 'Bangladesh', 'ARR100', 71, 1100),
        (58082, 'Unknown', 'Nabil34', 110, 1083),
        (59245, 'Bangladesh', 'tonoy_gscian', 64, 1074),
        (64302, 'Bangladesh', '_Musarrat_', 118, 1037),
        (67759, 'Bangladesh', 'Irfan_Shah', 7, 1013),
        (69562, 'Bangladesh', 'Mohaimen_Hridoy', 62, 1001),
        (70860, 'Bangladesh', 'mhidi', 32, 992),
        (73546, 'Bangladesh', 'shohanshovo10', 51, 974),
        (74600, 'Bangladesh', 'nabihaparvez11', 66, 967),
        (76721, 'Bangladesh', 'kabirsumaiya', 47, 954),
        (77745, 'Unknown', 'fahim_muhtachim', 5, 948),
        (78750, 'Bangladesh', '_Tamim', 21, 942),
        (80078, 'Bangladesh', 'Rafsan093', 41, 934),
        (80426, 'Bangladesh', 'sabbirMusfique', 18, 932),
        (81951, 'Bangladesh', 'Enamul_Marzun', 49, 923),
        (85592, 'Bangladesh', 'Ashria', 5, 902),
        (91899, 'Unknown', 'boshita_roy', 56, 868),
        (93190, 'Bangladesh', 'SMShakib', 31, 861),
        (93924, 'Bangladesh', 'Ashab_Raiyan', 6, 857),
        (95329, 'Bangladesh', 'rf_104', 23, 849),
        (96240, 'Unknown', 'Phisher101', 4, 844),
        (97151, 'Bangladesh', 'Machinist99', 50, 839),
        (97333, 'Bangladesh', 'NaWMee_Nawar', 16, 838),
        (97882, 'Unknown', 'Rashed_islam', 60, 835),
        (98402, 'Unknown', 'nawal_cp', 25, 832),
        (102806, 'Bangladesh', 'AL-MOBIN', 16, 808),
        (104728, 'Unknown', 'sarkarkabbo72', 3, 797),
        (104900, 'Bangladesh', 'ihsanul.huq.25', 5, 796),
        (108309, 'Bangladesh', 'Phoenix_101', 32, 776),
        (108309, 'Bangladesh', 'ADIB3883', 35, 776),
        (108634, 'Bangladesh', 'nkswapnil', 6, 774),
        (109755, 'Unknown', 'farhan_mugdho', 7, 767),
        (110651, 'Bangladesh', 'prottoyoops', 3, 761),
        (111939, 'Bangladesh', 'Toufikhossen321', 9, 752),
        (112959, 'Bangladesh', 'deActive', 20, 744),
        (115031, 'Bangladesh', 'alif405', 3, 726),
        (116657, 'Bangladesh', 'Matin005', 54, 710),
        (118375, 'Bangladesh', 'maliha290404', 6, 685),
        (125800, 'Bangladesh', 'Fasterhand539', 2, 614),
        (128537, 'Unknown', 'Rakib_09', 2, 595),
        (129099, 'Bangladesh', 'SiyamElaUwU2006', 2, 591),
        (131859, 'Unknown', 'afia_ema', 15, 558),
        (148316, 'Bangladesh', 'let_me_down', 1, 378),
        (155296, 'Unknown', 'suha_mila', 1, 363),
        (158444, 'Bangladesh', 'Munki_', 1, 357),
    ]
    
    # Additional users from the "unranked" section
    additional_users = [
        ('Bangladesh', 'mamun4122', 90, 1921),
        ('Bangladesh', 'Takik', 80, 1911),
        ('Bangladesh', 'sayedgkm', 102, 1904),
        ('Bangladesh', 'dipta007', 112, 1711),
        ('Bangladesh', 'Excogitatoris', 91, 1705),
        ('Bangladesh', 'asif3058', 61, 1679),
        ('Bangladesh', 'Raf_', 28, 1669),
        ('Bangladesh', '_Lucifer', 79, 1658),
        ('Bangladesh', 'Ihtiaz', 80, 1640),
        ('Bangladesh', 'rafsan_rana', 104, 1637),
        ('Bangladesh', '700atpid', 40, 1634),
        ('Unknown', 'drigger', 1, 1627),
        ('Bangladesh', 'RaFiN_', 42, 1627),
        ('Bangladesh', 'wazedrifat', 49, 1623),
        ('Bangladesh', 'RF_Faisal', 95, 1605),
        ('Bangladesh', 'proma_20196', 36, 1552),
        ('Bangladesh', 'Paagla_Coder', 46, 1492),
        ('Bangladesh', 'sayeer_24', 56, 1470),
        ('Bangladesh', 'wazedrifat1', 18, 1470),
        ('Bangladesh', 'EnderMan29.1', 8, 1464),
        ('Bangladesh', 'samee.sevas', 15, 1462),
        ('Bangladesh', 'adnanSharif', 42, 1443),
        ('Bangladesh', 'Quark01', 16, 1443),
        ('Bangladesh', 'sajid13', 58, 1438),
        ('Unknown', 'IRS_13', 1, 1420),
        ('Bangladesh', 'kamrul_ashraf', 70, 1414),
        ('Unknown', 'Sanjida17', 1, 1412),
        ('Bangladesh', 'iunknown', 1, 1407),
        ('Bangladesh', 'tawsifsazid', 1, 1406),
        ('Bangladesh', 'shafin034', 1, 1406),
        ('Bangladesh', 'sameesevas', 86, 1406),
        ('Bangladesh', 'rakib56', 79, 1400),
        ('Bangladesh', 'adibhossain', 56, 1398),
        ('Bangladesh', 's_a_tanjim', 1, 1375),
        ('Bangladesh', 'Malang', 23, 1374),
        ('Bangladesh', 'Tahidul_Saimon', 1, 1367),
        ('Bangladesh', '_MoHiudDiN_rE3ta7T_', 140, 1365),
        ('Bangladesh', 'trifiasco', 13, 1357),
        ('Bangladesh', 'tomb_raid3r', 59, 1354),
        ('Bangladesh', 'Mehedimuaz', 36, 1350),
        ('Bangladesh', 'fuadrafid', 2, 1343),
        ('Bangladesh', 'kivran_kp', 2, 1332),
        ('Bangladesh', 'afifatahira', 2, 1323),
        ('Bangladesh', 'Bonsai.', 36, 1322),
        ('Bangladesh', 'riddikulus', 24, 1314),
        ('Bangladesh', 'brownFalcon', 43, 1303),
        ('Bangladesh', 'ishraklancer', 2, 1299),
        ('Unknown', 'umair10', 2, 1284),
        ('Bangladesh', 'howcum', 63, 1260),
        ('Unknown', 'janTRik', 3, 1245),
        ('Bangladesh', 'Shakil_12', 3, 1238),
        ('Bangladesh', 'tanvirrazin', 3, 1233),
        ('Bangladesh', 'Abrar_Mahir_Esam', 65, 1229),
        ('Bangladesh', 'qshahrukh40', 4, 1226),
        ('Bangladesh', 'darkLuminance', 23, 1221),
        ('Bangladesh', 'szaman034', 18, 1219),
        ('Bangladesh', 'Rizon_Sunny', 66, 1209),
        ('Bangladesh', 'IceBank29', 47, 1207),
        ('Bangladesh', 'Rupu', 30, 1206),
        ('Bangladesh', 'RaiyanJahangir', 36, 1206),
        ('Bangladesh', 'NiverdPereira', 55, 1199),
        ('Bangladesh', 'namratamist14', 3, 1197),
        ('Bangladesh', 'Mir_Ashraf', 68, 1196),
        ('Bangladesh', 'SRI.JBL', 3, 1190),
        ('Bangladesh', 'arnab5574', 11, 1161),
        ('Bangladesh', 'Kazi_Md._Munim', 15, 1143),
        ('Bangladesh', 'muhaiminbinmunir', 50, 1138),
        ('Bangladesh', 'shapnil092', 38, 1135),
        ('Bangladesh', 'srijonsbzsifat', 44, 1131),
        ('Bangladesh', 'SaifurRahman656', 8, 1130),
        ('Bangladesh', 'anindita_94', 27, 1110),
        ('Bangladesh', 'Md_Nahiduzzamann', 71, 1103),
        ('Bangladesh', 'splash365', 38, 1102),
        ('Unknown', 'EnderMan29.3', 19, 1099),
        ('Bangladesh', 'proteeti_13', 4, 1093),
        ('Bangladesh', 'Tahmid46', 8, 1083),
        ('Bangladesh', '131tahmid', 7, 1082),
        ('Bangladesh', 'saiful_azad', 65, 1072),
        ('Bangladesh', 'alamarif', 5, 1054),
        ('Bangladesh', 'tashfiq12', 80, 1043),
        ('Bangladesh', '__DeStinyBond__', 15, 1042),
        ('Unknown', 'sabbir_ul_alam', 8, 1038),
        ('Bangladesh', 'Shejuti_Binte_Feroz', 67, 1019),
        ('Bangladesh', 'Siifu', 23, 1018),
        ('Bangladesh', 'Md.Ismile', 4, 1015),
        ('Bangladesh', 'Ahasan', 7, 999),
        ('Bangladesh', 'M1437', 9, 992),
        ('Bangladesh', 'shaswati', 33, 985),
        ('Unknown', 'Rubaid_S09', 8, 985),
        ('Bangladesh', 'alif_uL_haQue', 36, 984),
        ('Bangladesh', 'dhrubo_mahbub', 7, 971),
        ('Bangladesh', 'ahmedrihin', 26, 968),
        ('Bangladesh', 'shahir', 8, 967),
        ('Bangladesh', 'Anik_the_great', 43, 965),
        ('Bangladesh', 'Makshudul', 42, 963),
        ('Bangladesh', 'AnanERA', 75, 950),
        ('Bangladesh', 'minsatahseyam', 31, 939),
        ('Bangladesh', 'Ellora_12', 97, 932),
        ('Bangladesh', 'mayo123', 16, 917),
        ('Bangladesh', 'scoobie_doobie', 3, 910),
        ('Bangladesh', 'KronoFaze', 21, 909),
        ('Bangladesh', 'emon.49', 81, 902),
        ('Unknown', 'avy63', 10, 901),
        ('Bangladesh', 'ismail19', 19, 883),
        ('Bangladesh', 'Scomrades', 7, 881),
        ('Bangladesh', 'imran4215', 20, 863),
        ('Bangladesh', 'irresistabledudex2', 7, 862),
        ('Bangladesh', 'shahriar07', 8, 860),
        ('Bangladesh', 'Ayon_Roy', 11, 859),
        ('Unknown', 'humayraakter25', 13, 849),
        ('Bangladesh', 'deadshoot333', 6, 842),
        ('Bangladesh', 'Saimon_', 11, 828),
        ('Bangladesh', 'Darth_Vader_', 44, 808),
        ('Bangladesh', 'shadreza', 19, 808),
        ('Bangladesh', 'tasnimtaz87', 7, 804),
        ('Bangladesh', 'khaledirfan', 14, 800),
        ('Bangladesh', 'maliha20414', 6, 768),
        ('Unknown', 'Mist_Team_Pegasus', 3, 743),
        ('Bangladesh', 'S.M._Nafis_Ahmed', 37, 729),
        ('Bangladesh', 'Finder111', 3, 709),
        ('Bangladesh', 'mission27', 7, 702),
        ('Bangladesh', 'BUGSs_bunny', 13, 699),
        ('Bangladesh', 'min27', 21, 694),
        ('Unknown', 'Tamim_Rizvee', 24, 646),
        ('Bangladesh', 'shafin69', 2, 632),
        ('Bangladesh', 'EmonRezaBD', 18, 472),
        ('Bangladesh', 'Ghosh_Bijoya', 1, 376),
    ]
    
    # Convert to list of dictionaries
    users_data = []
    
    # Add ranked users
    for i, (rank, country, username, contests, rating) in enumerate(manual_data):
        users_data.append({
            'Global_Rank': rank,
            'Organization_Rank': i + 1,
            'Country': country,
            'Username': username,
            'Contests': contests,
            'Rating': rating
        })
    
    # Add unranked users
    for country, username, contests, rating in additional_users:
        users_data.append({
            'Global_Rank': None,
            'Organization_Rank': None,
            'Country': country,
            'Username': username,
            'Contests': contests,
            'Rating': rating
        })
    
    return users_data

def save_to_csv(data, filename):
    """
    Save data to CSV file
    """
    if not data:
        print("No data to save!")
        return
    
    df = pd.DataFrame(data)
    
    # Sort by rating in descending order
    df = df.sort_values('Rating', ascending=False)
    
    # Save to CSV
    df.to_csv(filename, index=False, encoding='utf-8')
    print(f"Data saved to {filename}")
    print(f"Total users: {len(df)}")
    print(f"Columns: {list(df.columns)}")
    
    # Display first few rows
    print("\nFirst 10 rows:")
    print(df.head(10).to_string(index=False))
    
    # Display statistics
    print(f"\nStatistics:")
    print(f"Highest rating: {df['Rating'].max()}")
    print(f"Lowest rating: {df['Rating'].min()}")
    print(f"Average rating: {df['Rating'].mean():.2f}")
    print(f"Total contests participated: {df['Contests'].sum()}")
    
    # Country distribution
    print(f"\nCountry distribution:")
    country_counts = df['Country'].value_counts()
    print(country_counts)

def main():
    """
    Main function to fetch and save Codeforces organization data
    """
    org_id = 1162
    
    print("Fetching Codeforces Organization 1162 data...")
    
    # Try to fetch data from web first
    data = fetch_codeforces_organization_data(org_id)
    
    # If web scraping doesn't work well, use manual data
    if len(data) < 50:  # If we got less data than expected
        print("Using manually parsed data from the webpage...")
        data = parse_manual_data()
    
    if data:
        filename = f"codeforces_org_{org_id}_usernames.csv"
        save_to_csv(data, filename)
    else:
        print("Failed to fetch data!")

if __name__ == "__main__":
    main()