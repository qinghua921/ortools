export class DecisionBuilder
{
    //     public:
    //      DecisionBuilder() {}

    //    #ifndef SWIG
    //      // This type is neither copyable nor movable.
    //      DecisionBuilder(const DecisionBuilder&) = delete;
    //      DecisionBuilder& operator=(const DecisionBuilder&) = delete;
    //    #endif
    //      ~DecisionBuilder() override {}
    //      /// This is the main method of the decision builder class. It must
    //      /// return a decision (an instance of the class Decision). If it
    //      /// returns nullptr, this means that the decision builder has finished
    //      /// its work.
    //      virtual Decision* Next(Solver* s) = 0;
    //      std::string DebugString() const override;
    //    #if !defined(SWIG)
    //      /// This method will be called at the start of the search.  It asks
    //      /// the decision builder if it wants to append search monitors to the
    //      /// list of active monitors for this search. Please note there are no
    //      /// checks at this point for duplication.
    //      virtual void AppendMonitors(Solver* solver,
    //                                  std::vector<SearchMonitor*>* extras);
    //      virtual void Accept(ModelVisitor* visitor) const;
    //    #endif
    //      void set_name(absl::string_view name) { name_ = name; }
    //      std::string GetName() const;

    //     private:
    //      std::string name_;
};
