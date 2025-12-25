# Route Optimization Logic 
bins_data = [
    {"id": 1, "level": 85, "location": (17.38, 78.48)}, # Critical
    {"id": 2, "level": 30, "location": (17.39, 78.49)}, # Skip
    {"id": 3, "level": 60, "location": (17.40, 78.47)}  # Optional
]

def plan_route(bins):
    # 1. Filter High Priority (>80%) [cite: 90, 106]
    must_collect = [b for b in bins if b['level'] > 80]
    
    # 2. Add Medium Priority (50-80%) if nearby [cite: 90, 96]
    optional = [b for b in bins if 50 < b['level'] <= 80]
    
    # 3. Sort by proximity (Nearest Neighbor) [cite: 92, 126]
    # Logic to return optimized path...
    return must_collect

print("Optimized Collection Route:", plan_route(bins_data))