program h_1180_jiuzhenqushuyouxiwugaojingduban_DP_2017_4_10;
var
  f:array[0..80,0..80] of qword;
  a:array[1..80] of qword;
  n,m,i,j,k:byte;
  ans:qword;
function max(a,b:qword):qword;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[j]);
    fillchar(f,sizeof(f),0);
    for j:=m downto 1 do
      for k:=j to m do
        f[j,k]:=max(a[j]*(1shl(m-k+j))+f[j+1,k],a[k]*(1shl(m-k+j))+f[j,k-1]);
    inc(ans,f[1,m]);
  end;
  writeln(ans);
end.



