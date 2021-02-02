class Solution {
    public String frequencySort(String s) {
        if (s == null || s.isEmpty()) return s;
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        
        List<String> charStrings = new ArrayList<String>();
        StringBuilder builder = new StringBuilder();
        builder.append(chars[0]);
        for (int i = 1;i < chars.length; i++) {
            if (chars[i] != chars[i - 1]) {
                charStrings.add(builder.toString());
                builder = new StringBuilder();
            }
            builder.append(chars[i]);
        }
        charStrings.add(builder.toString());
        
        Collections.sort(charStrings, (lhs, rhs) -> rhs.length() - lhs.length());
        
        StringBuilder sb = new StringBuilder();
        charStrings.forEach((element) -> sb.append(element));
        
        return sb.toString();
    }
}