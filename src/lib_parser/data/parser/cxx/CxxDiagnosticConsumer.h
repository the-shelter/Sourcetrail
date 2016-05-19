#ifndef CXX_DIAGNOSTIC_CONSUMER
#define CXX_DIAGNOSTIC_CONSUMER

#include "clang/Frontend/TextDiagnosticPrinter.h"

class ParserClient;

class CxxDiagnosticConsumer
	: public clang::TextDiagnosticPrinter
{
public:
	CxxDiagnosticConsumer(
		clang::raw_ostream &os,
		clang::DiagnosticOptions *diags,
		ParserClient* client,
		bool useLogging = true
	);

	void BeginSourceFile(const clang::LangOptions& langOptions, const clang::Preprocessor* preProcessor);
	void EndSourceFile();

	void HandleDiagnostic(clang::DiagnosticsEngine::Level level, const clang::Diagnostic& info);

private:
	ParserClient* m_client;
	bool m_isParsingFile;
	bool m_useLogging;
};

#endif // CXX_DIAGNOSTIC_CONSUMER
