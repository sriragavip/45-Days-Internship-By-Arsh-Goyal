class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res=[]
        line,l=[],0
        for w in words:
            l+=len(w)
            line.append(w)
            spaces_min=len(line)-1
            
            if l+spaces_min==maxWidth:
                res.append(" ".join(line))
                line=[]
                l=0
            elif l+spaces_min>maxWidth:
                # last word is not included in this line (does not fit)
                spaces_req=maxWidth-l+len(w)
                words=len(line)-1
                
                spaced_line=[]
                spaces_per_word=spaces_req//(words-1) if words>1 else spaces_req
                overflow=spaces_req%(words-1) if words>1 else 0
                for i in range(words):
                    spaced_line.append(line[i])
                    if i<words-1 or words==1:
                        spaced_line.append(" " * (spaces_per_word + (1 if overflow else 0)))
                        if overflow: overflow-=1
                    
                res.append("".join(spaced_line))
                line=line[-1:]
                l=len(line[0])
            
        if line:
            spaced_line=" ".join(line)
            spaces_req=maxWidth-len(spaced_line)
            res.append(spaced_line + " " * spaces_req)
        return res