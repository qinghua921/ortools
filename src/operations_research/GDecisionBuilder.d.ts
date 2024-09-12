/// A DecisionBuilder is responsible for creating the search tree. The
/// important method is Next(), which returns the next decision to execute.
export class DecisionBuilder
{
    //     public:
    //      DecisionBuilder() {}
    //      ~DecisionBuilder() override {}
    //      /// This is the main method of the decision builder class. It must
    //      /// return a decision (an instance of the class Decision). If it
    //      /// returns nullptr, this means that the decision builder has finished
    //      /// its work.
    //      virtual Decision* Next(Solver* const s) = 0;
    //      std::string DebugString() const override;
    //    #if !defined(SWIG)
    //      /// This method will be called at the start of the search.  It asks
    //      /// the decision builder if it wants to append search monitors to the
    //      /// list of active monitors for this search. Please note there are no
    //      /// checks at this point for duplication.
    //      virtual void AppendMonitors(Solver* const solver,
    //                                  std::vector<SearchMonitor*>* const extras);
    //      virtual void Accept(ModelVisitor* const visitor) const;
    //    #endif
    //      void set_name(const std::string& name) { name_ = name; }
    //      std::string GetName() const;

};
