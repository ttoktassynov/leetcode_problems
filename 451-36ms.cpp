class Solution {
    public String frequencySort(String s) {
        if (s == null || s.isEmpty()) return s;
        
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for(char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }
        int maxFrequency = Collections.max(freqMap.values());
        
        List<List<Character>> buckets = new ArrayList<>();
        for (int i = 0; i <= maxFrequency; i++) {
            buckets.add(new ArrayList<Character>());
        }
        for (Character key: freqMap.keySet()) {
            int freq = freqMap.get(key);
            buckets.get(freq).add(key);
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = buckets.size() - 1; i >= 1; i--) {
            for (Character c: buckets.get(i)) {
                for (int j = 0;j < i; j++){
                    sb.append(c);
                }
            }
        }
        return sb.toString();
        
    }
}