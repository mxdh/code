program jg_d4_2017_3_12;
var
  a:array[1..10000] of longint;
  n,i,t,l,d,ans:longint;
procedure put(num:longint);
var f,s:integer;
begin
  inc(l);
  a[l]:=num; s:=l;
  while (s>1)and(a[s div 2]>a[s]) do
  begin
    inc(a[s div 2],a[s]);
    a[s]:=a[s div 2]-a[s];
    dec(a[s div 2],a[s]);
    s:=s div 2;
  end;
end;
function get:longint;
var
  f,s:integer;
  stop:boolean;
begin
  get:=a[1]; a[1]:=a[l];
  dec(l);
  f:=1; stop:=true;
  while stop and(f*2<=l) do
  begin
    if (f*2+1>l)or(a[f*2]<a[f*2+1])
    then s:=f*2
    else s:=f*2+1;
    if a[f]>a[s]
    then begin
           inc(a[f],a[s]);
           a[s]:=a[f]-a[s];
           dec(a[f],a[s]);
           f:=s;
         end
    else stop:=false;
  end;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(t);
    put(t);
  end;
  for i:=1 to n-1 do
  begin
    d:=get+get;
    inc(ans,d);
    put(d);
  end;
  writeln(ans);
end.


