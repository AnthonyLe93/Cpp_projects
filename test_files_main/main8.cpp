#include <iostream>
#include <string>

/* Smart pointers (shared_pointer) */
class Project {
    std::string m_Name;

public:
    void SetName(const std::string &name){
        m_Name = name;
    }
    void ShowProjectDetails()const{
        std::cout << "[Project]" << m_Name << std::endl;
    }

};


class Employee {
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject(std::shared_ptr<Project> & prj){
        m_pProject = prj;
    }
    const std::shared_ptr<Project> & GetProject()const {
        return m_pProject;
    }
};

void ShowInfo(const std::shared_ptr<Employee> & emp){
    std::cout << "Employee project details: ";
    emp->GetProject()->ShowProjectDetails();
}

int main8() {
    std::shared_ptr<Project> prj {new Project{}};
    prj ->SetName("Video Decoder");
    std::shared_ptr<Employee> e1 {new Employee{}};
    e1 ->SetProject(prj);
    std::shared_ptr<Employee> e2 {new Employee{}};
    e2 ->SetProject(prj);
    std::shared_ptr<Employee> e3 {new Employee{}};
    e3 ->SetProject(prj);

    if(e3)
        std::cout << "valid pointer" << std::endl;
    else
        std::cout << "invalid pointer" << std::endl;

    std::cout << "Reference count: " << prj.use_count() << "\n";
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();

}