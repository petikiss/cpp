program Meterlogia;
uses crt; // a crt modult szeretnenk hasznalni, mert ebben van a ClrScr() fuggveny elkeszitve (definialva)

type
   MatrixType   = array of array of integer; // csinalunk egy matrix tipust, amibe integereket tudunk tarolni
   ArrayType =  array of integer;


// ez a fuggveny megnezi, hogy az N vagy az M kisebb e mint 1
// procedure(eljaras) es function(fuggveny) kozott az a kulonbseg, hogy a functionnak van visszateresi erteke, a procedure-nak nincs
function HelyesekAParameterek(N : integer; M : integer ) : boolean;
begin
   HelyesekAParameterek := true; // a fuggveny visszateresi erteket kezdetben true-ra allitjuk

   // ha a varosok szama 1-nel kisebb
   if N < 1  then
   begin
      HelyesekAParameterek := false;
   end;

   // ha a napok szama 1-nel kisebb
   if M < 1  then
   begin
      HelyesekAParameterek := false;
   end;
end;



procedure AdatokBeolvasasaBillentyuzetrol(var Matrix : MatrixType; var N : integer; var M : integer; var F : integer);
  var i,j : integer; // ciklus valtozok deklaralasa
begin
   Write('Hany telepules van?: ');
   ReadLn(N);
   Write('Hany naposak az elorejelzesek?: ');
   ReadLn(M);
   Write('Mekkora homersekletet keresunk?: ');
   ReadLn(F);

   if HelyesekAParameterek(N,M) = true then
   begin
      SetLength(Matrix, N, M); // az elobb kertuk be billentyuzetrol a matrix mereteit, ezert most beallitjuk

      // A tombok alapban 0-tol indexelodnek (szoval az "elso" eleme a 0-dik elem, ezert kell menni 0-tol N-1ig. Igy jon ki az Ndb elem)
      // Ha ugye 0tol Nig mennenk, akkor tulindexelunk, mert N+1 elemen mennenk vegig!!! Az indexeleseket nagyon konnyu elrontani, raadasul,
      // futasi idoben derulnek ki ezek a hibak (a program abortal, leall)
      for i:=0 to N-1 do
      begin
         for j:=0 to M-1 do
         begin
            Write(i+1,'-dik varos ',j+1,' napi homerseklete: ');
            ReadLn(Matrix[i,j]);
         end;
      end;
   end
end;



// A fajl elso sora tartalmazza a varosok szamat (N)
// masodik sora a mert napok szamat (M)
// harmadik sora az F-et
// majd a matrix jon
procedure AdatokBeolvasasaFajlbol(var Matrix : MatrixType; var N : integer; var M : integer; var F : integer; FajlNev : string);
var Fajl : text;
var i,j : integer;
begin
   Assign(Fajl, FajlNev); // A Fajl valtozonak megadjuk, hogy milyen nevu fajlt (FajlNev) kezeljen

   {$I-} // kikapcsoljuk a hibakat (ha pl. ha nincs meg a fajl, akkor ne abortaljon a program)
   Reset(Fajl); // Megnyitjuk a Fajl-t olvasasra a Reset fuggvennyel
   {$I+} // visszakapcsoljuk a hibakat

   if ioresult <> 0 then
   begin
      WriteLn(FajlNev, ' nevu fajlt nem sikerult megnyitni!');
      halt;
   end;

   ReadLn(Fajl,N); // olvasunk egy sort a fajlbol (az elso sor a varosok szamat tartalmazza)
   ReadLn(Fajl,M);
   ReadLn(Fajl,F);

   if HelyesekAParameterek(N,M) = true then
   begin
      SetLength(Matrix, N, M);
      i := 0;
      while not eof(Fajl) do // amig nincs vege a fajlnak addig menjen a while ciklus (eof = End Of File)
      begin
         j := 0;
         while not eoln(Fajl) do // amig nincs vege a sornak (eoln = End Of LiNe)
         begin
            Read(Fajl, Matrix[i,j]); // A Read fuggveny olvas az adott sorban whitespace-ig -> a fajlban az adatok az adott sorban direkt szokozokkel vannak elvalasztva
            j := j + 1;
         end;
         ReadLn(Fajl); // beolvasunk egy uj sort
         i := i + 1;
      end;
   end;

   Close(Fajl); // a fajlt a Resettel megnyitottuk olvasasra, a Close()-al pedig jelezzuk, hogy tobbet nem olvasunk belole
end;


// Keressuk azokat az oszlopokat, ahol minden szam nagyobb, mint F (M db felt linker N hosszu tombokon)
// Ennek a procedure-nak 6 db parametere van: Matrix, N, M, F, Eredmeny, EredmenySzama
// Az Eredmeny es az EredmenySzama elott szerepel a var kulcsszo, aminek teljesen mar a jelentese, mint deklaralasnal
// Itt azt jelenti, hogy ezek ki-be meno parameterek, azaz ha a procedure-n belul megvaltoztatjuk az ertekeit, akkor
// ezek az erteket "visszamennek" a hivas helyere
procedure Kereses(Matrix : MatrixType; N : integer; M: integer; F : integer; var Eredmeny : ArrayType; var EredmenySzama : integer);
var i,j : integer;
var talalt :  boolean;
begin
   for j:=0 to M-1 do
   begin
      talalt := true;
      for i:=0 to N-1 do
      begin
         if Matrix[i,j] < F then
         begin
            talalt := false;
         end;
      end;
      if talalt = true then
      begin
         Eredmeny[EredmenySzama] := j + 1;
         EredmenySzama := EredmenySzama + 1;
      end;
   end;
end;


// itt csak bemeno parameterek vannak. Ha pl. valozna az N erteke, akkor csak a proceduran belul valtozna
// ahonnan meghivtuk ezt a procedura-t, ott nem fog N erteke valtozni
procedure MatrixotKiir(Matrix : MatrixType; N : integer; M : integer );
var i,j : integer;
begin
   for i:=0 to N-1 do
   begin
      for j:=0 to M-1 do
      begin
         Write(Matrix[i,j], ' ');
      end;
      WriteLn();
   end;
end;


procedure EredmenytKiir(Eredmeny : ArrayType; EredmenySzama : integer; F : integer);
var i : integer;
begin
   if EredmenySzama = 0 then
   begin
      Write('Egyik napon sem volt legalabb ', F, ' fok minden varosban!');
   end
   else
   begin
      Write('A kovetkezo nap(okon) volt legalabb ',F, ' fok minden varosban: ');
      for i:=0 to EredmenySzama-1 do
      begin
         Write(Eredmeny[i],' ');
      end;
   end;
end;


// itt indul a program
var Matrix : MatrixType; // a type reszben csinaltunk egy MatrixType tipust, most ezt felhasznaljuk
var Eredmeny :  ArrayType; // azokat a napokat fogja tartalmazni, amenyeken a homerseklet nagyobb, mint "F"
var EredmenySzama : integer;
var N             : integer; // varosok szama
var M             : integer; // mert homersekletek szama
var F          : integer;
var FajlNev :  string;
begin
   ClrScr(); // letoroljuk a kepernyot

   if ParamCount = 1 then // a ParamCount beepitett valtozo, megadja, hogy hany parametere volt a programnak (pl: "meterologia.exe input1.txt")
   begin
      FajlNev := ParamStr(1); // a ParamStr() beepitett fuggveny, ami visszaadja a 1-dik parameter erteket
      WriteLn('Beolvasas a(z) ', FajlNev, ' fajlbol...'); // Kiiratunk a kepernyore (A Write es a WriteLn kozott a kulonbseg, hogy a WriteLn egy uj sort is pluszba kiir a kepernyore)
      AdatokBeolvasasaFajlbol(Matrix, N, M, F, FajlNev); // meghivjuk a fennt elkeszitett fuggvenyunket
   end // Figyelem: itt kivetelesen nem kell pontos vesszo az "end" vegere. Fura szintaxis ...
   else
   begin
         AdatokBeolvasasaBillentyuzetrol(Matrix, N, M, F);
   end;

   if HelyesekAParameterek(N,M) = true then
   begin
      SetLength(Eredmeny,M); // maximalisan M db eredmenyunk lehet (ha minden nap mindenhol legalabb F a homerseklet)
      Kereses(Matrix, N, M, F, Eredmeny, EredmenySzama);
      MatrixotKiir(Matrix, N, M);
      EredmenytKiir(Eredmeny,EredmenySzama, F);
   end
   else
   begin
      WriteLn('Helytelen parameter(ek)! (N>1, M>1)');
   end;
   Readln;
end.
