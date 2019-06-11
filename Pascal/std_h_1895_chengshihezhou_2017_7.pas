program std_h_1895_chengshihezhou_2017_7_12;
type na=array[1..2] of char;
var
  z,c:array[1..200000] of na;
  n,i,j,p,a:longint;
  s:string;
procedure sort(l,r:longint);
var
  i,j,m:longint;
  x1,x2,y:na;
begin
  i:=l; j:=r; m:=(l+r)div 2;
  x1:=z[m]; x2:=c[m];
  repeat
    while (z[i]<x1)or(z[i]=x1)and(c[i]<x2) do inc(i);
    while (x1<z[j])or(x1=z[j])and(x2<c[j]) do dec(j);
    if i<=j then
    begin
      y:=z[i]; z[i]:=z[j]; z[j]:=y;
      y:=c[i]; c[i]:=c[j]; c[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      c[i,1]:=s[1]; c[i,2]:=s[2];
      p:=pos(' ',s);
      z[i,1]:=s[p+1]; z[i,2]:=s[p+2];
    end;
  sort(1,n);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (z[i]=c[j])and(z[j]=c[i]) then
      begin
         //writeln(i,' ',j,' ',z[i],' ',c[i],' ',z[j],' ',c[j]);
         inc(a);
      end;
  writeln(a);
end.
