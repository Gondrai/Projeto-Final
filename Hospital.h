class Hospital
{
private:
    vector<Ala> alas; //Vetor que armazena as alas do hospital
    ArquivoPacientes arquivoPacientes;

public:
    Hospital();
    Hospital(int total_alas);
    ~Hospital();
    void Create();                // Insere uma ala nova
    void Create(Ala ala);         // Insere uma ala feita
    void Create(ArquivoPacientes arquivo);
    void Delete();                // Deleta a ultima ala
    void Delete(int pos);         // Deleta uma ala especifica
    void relatorio_estatistico(); // Relatórios
};
