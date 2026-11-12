#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Estudiante {
    string nombre;
    int anioNacimiento;
    double gpa;
    double presupuesto;

    double calcularIndiceUniversidad() const {
        return abs(gpa - 3.0) * presupuesto;
    }
};

void imprimirEstudiantes(const vector<Estudiante>& estudiantes) {
    cout << "\nLISTADO ACTUAL DE ESTUDIANTES" << endl;
    if (estudiantes.empty()) {
        cout << " El vector de estudiantes esta vacio." << endl;
    } else {
        for (size_t i = 0; i < estudiantes.size(); i++) {
            cout << "Indice [" << i << "]:" << endl;
            cout << " - Nombre: " << estudiantes[i].nombre << endl;
            cout << " - Año de Nacimiento: " << estudiantes[i].anioNacimiento << endl;
            cout << " - GPA: " << estudiantes[i].gpa << endl;
            cout << " - Presupuesto: " << estudiantes[i].presupuesto << endl;
            cout << " - Indice Universidad: " << estudiantes[i].calcularIndiceUniversidad() << endl << endl;
        }
    }
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;

    do {
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. Ingresar estudiante" << endl;
        cout << "2. Eliminar estudiante" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Ordenar estudiantes" << endl;
        cout << "5. Imprimir estudiantes" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int tipoInsercion, modoDatos;
                cout << "\nINSERTAR ESTUDIANTE" << endl;
                cout << "1. Insertar al final" << endl;
                cout << "2. Insertar en un indice especifico" << endl;
                cout << "Elija opcion: ";
                cin >> tipoInsercion;

                cout << "1. Por defecto" << endl;
                cout << "2. Con datos personalizados" << endl;
                cout << "Elija modo: ";
                cin >> modoDatos;

                Estudiante nuevoEst;
                if (modoDatos == 1) {
                    nuevoEst = {"NN", 0, 0.0, 0.0};
                } else {
                    cout << "Ingrese nombre: ";
                    cin >> nuevoEst.nombre;
                    cout << "Ingrese año de nacimiento: ";
                    cin >> nuevoEst.anioNacimiento;
                    cout << "Ingrese GPA: ";
                    cin >> nuevoEst.gpa;
                    cout << "Ingrese presupuesto: ";
                    cin >> nuevoEst.presupuesto;
                }

                if (tipoInsercion == 1) {
                    estudiantes.push_back(nuevoEst);
                    cout << "[Exito] Estudiante insertado al final." << endl;
                } else if (tipoInsercion == 2) {
                    size_t idx;
                    cout << "Ingrese el indice (0 a " << estudiantes.size() << "): ";
                    cin >> idx;
                    if (idx <= estudiantes.size()) {
                        estudiantes.insert(estudiantes.begin() + idx, nuevoEst);
                        cout << "[Exito] Estudiante insertado en el indice " << idx << "." << endl;
                    } else {
                        cout << "[Error] Indice fuera de rango." << endl;
                    }
                }
                break;
            }
            case 2: {
                cout << "\nELIMINAR ESTUDIANTE" << endl;
                if (estudiantes.empty()) {
                    cout << "[Aviso] La lista esta vacía. No se puede eliminar." << endl;
                    break;
                }

                int tipoEliminacion;
                cout << "1. Eliminar el ultimo elemento" << endl;
                cout << "2. Eliminar desde un indice especifico" << endl;
                cout << "Elija opcion: ";
                cin >> tipoEliminacion;

                if (tipoEliminacion == 1) {
                    estudiantes.pop_back();
                    cout << "[Exito] Ultimo estudiante eliminado." << endl;
                } else if (tipoEliminacion == 2) {
                    size_t idx;
                    cout << "Ingrese el indice a eliminar (0 a " << estudiantes.size() - 1 << "): ";
                    cin >> idx;
                    if (idx < estudiantes.size()) {
                        estudiantes.erase(estudiantes.begin() + idx);
                        cout << "[Exito] Estudiante en el indice " << idx << " eliminado." << endl;
                    } else {
                        cout << "[Error] Indice invalido." << endl;
                    }
                }
                break;
            }
            case 3: {
                cout << "\nACTUALIZAR ESTUDIANTE" << endl;
                if (estudiantes.empty()) {
                    cout << "[Aviso] El vector esta vacio." << endl;
                    break;
                }
                size_t idx;
                cout << "Ingrese el indice del estudiante a actualizar (0 a " << estudiantes.size() - 1 << "): ";
                cin >> idx;

                if (idx < estudiantes.size()) {
                    cout << "Actualizando estudiante en indice " << idx << ":" << endl;
                    cout << "Nuevo nombre: ";
                    cin >> estudiantes[idx].nombre;
                    cout << "Nuevo año de nacimiento: ";
                    cin >> estudiantes[idx].anioNacimiento;
                    cout << "Nuevo GPA: ";
                    cin >> estudiantes[idx].gpa;
                    cout << "Nuevo presupuesto: ";
                    cin >> estudiantes[idx].presupuesto;
                    cout << "[Exito] Datos actualizados correctamente." << endl;
                } else {
                    cout << "[Error] Indice fuera de rango." << endl;
                }
                break;
            }
            case 4: {
                cout << "\nORDENAR ESTUDIANTES" << endl;
                if (estudiantes.empty()) {
                    cout << "[Aviso] El vector esta vacio, no hay nada que ordenar." << endl;
                    break;
                }

                int criterio;
                cout << "1. Por año de nacimiento" << endl;
                cout << "2. Por GPA" << endl;
                cout << "3. Por presupuesto" << endl;
                cout << "4. Por Indice Universidad" << endl;
                cout << "Elija criterio: ";
                cin >> criterio;

                if (criterio == 1) {
                    sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
                        return a.anioNacimiento < b.anioNacimiento;
                    });
                    cout << "[Exito] Ordenado por año de nacimiento." << endl;
                } else if (criterio == 2) {
                    sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
                        return a.gpa < b.gpa;
                    });
                    cout << "[Exito] Ordenado por GPA." << endl;
                } else if (criterio == 3) {
                    sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
                        return a.presupuesto < b.presupuesto;
                    });
                    cout << "[Exito] Ordenado por presupuesto." << endl;
                } else if (criterio == 4) {
                    sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
                        return a.calcularIndiceUniversidad() < b.calcularIndiceUniversidad();
                    });
                    cout << "[Exito] Ordenado por Indice Universidad." << endl;
                } else {
                    cout << "[Error] Criterio invalido." << endl;
                }
                imprimirEstudiantes(estudiantes);
                break;
            }
            case 5:
                imprimirEstudiantes(estudiantes);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}