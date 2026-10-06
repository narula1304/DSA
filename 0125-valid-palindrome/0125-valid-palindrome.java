class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();
        String str = "";
        for(int i=0;i<n;i++){
            char c = s.charAt(i);

            if(Character.isDigit(c) || Character.isLetter(c)){
                c = Character.toLowerCase(c);
                str += c;
            }
        }

        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            if(str.charAt(i) != str.charAt(j)) return false;
            i++;
            j--;
        }

        return true;
    }
}