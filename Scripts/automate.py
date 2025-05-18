import webbrowser
import time
import random
import pyautogui  # Install using: pip install pyautogui
import os

# Import the search terms from search_terms.py
try:
    from search_terms import search_terms
    if not search_terms or not isinstance(search_terms, list):
        raise ValueError("search_terms must be a non-empty list")
except ImportError:
    print("[ERROR] search_terms.py not found! Ensure it's in the same directory.")
    exit(1)
except ValueError as e:
    print(f"[ERROR] {e}")
    exit(1)


# Debug: Show starting message
print("Starting searches...\n")
time.sleep(15)
# Perform searches in a loopme
for i in range(35):
    search_term_for_edge = random.choice(search_terms)
    search_term_for_chrome = random.choice(search_terms)

    # Search in Edge
    pyautogui.click(450, 200)  # Adjust based on actual position
    pyautogui.write(search_term_for_edge, interval=random.uniform(0.2, 0.3))
    pyautogui.press("enter")
    print(f"Search {i+1} in Edge: {search_term_for_edge}")

    # Search in Chrome
    pyautogui.click(1550, 160)  # Adjust based on actual position
    pyautogui.write(search_term_for_chrome, interval=random.uniform(0.2, 0.3))
    pyautogui.press("enter")
    print(f"Search {i+1} in Chrome: {search_term_for_chrome}")

    # Wait before next searcha
    time.sleep(random.randint(3, 6))

    # Clear search bar (Edge)
    pyautogui.click(450, 200)
    pyautogui.hotkey('ctrl', 'a')
    time.sleep(1)
    pyautogui.press('delete')

    # Clear search bar (Chrome)
    pyautogui.click(1550, 160)
    pyautogui.hotkey('ctrl', 'a')
    time.sleep(1)
    pyautogui.press('delete')

# Debug: Completion message
print("\nCompleted all searches!")