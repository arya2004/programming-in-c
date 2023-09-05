/*
 * THIS IS IN C# (C-SHARP) AND NOT JAVA
 * VALUE OF B0 AND B1 IS LOADED AND PRINTED IN Output.txt
 * PLEASE USE A DEBUGGER TO CECK THE VALUES IN B0 AND B1
 * ALSO ONLY WORKS WITH 10 INSTRUCTIONS AT A TIME
 * PLEASE SPECIFY THE CORRECT PATH FOR INPUT AND OUTPUT FILE
 
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OS_Phase_1
{


    public class ExternalMemory
    {
        public char[,] Memory { get; set; }
        public int _Blocks { get; set; }
        public int _WordLength { get; set; }
        public int _WordsPerBlock { get; set; }

        public ExternalMemory(int WordLength, int Blocks, int WordsPerBlock)
        {
            Memory = new char[WordsPerBlock * Blocks, WordLength];
            _WordLength = WordLength;
            _Blocks = Blocks;
            _WordsPerBlock = WordsPerBlock;

        }

        public char[] GetWord(int Address)
        {
            char[] Word = new char[_WordLength];
            for (int i = 0; i < _WordLength; i++)
            {
                Word[i] = Memory[Address, i];
            }
            return Word;
        }
        public void SetWord(int Address, char[] Word)
        {
            for (int i = 0; i < _WordLength; i++)
            {
                Memory[Address, i] = Word[i];
            }
        }

        public char[,] GetBlock(int BlockAddress)
        {
            char[,] Block = new char[_WordsPerBlock, _WordLength];

            for (int i = 0; i < _WordsPerBlock; i++)
            {
                for (int j = 0; j < _WordLength; j++)
                {
                    Block[i, j] = Memory[(BlockAddress * _WordsPerBlock) + i, j];
                }
            }
            return Block;
        }

        public void SetBlock(char[,] GivenBloc, int BlockAddress)
        {
            for (int i = 0; i < _WordsPerBlock; i++)
            {
                for (int j = 0; j < _WordLength; j++)
                {
                    Memory[(BlockAddress * _WordsPerBlock) + i, j] = GivenBloc[i, j];
                }
            }

        }
        public void SetBlock(char[] GivenBloc, int BlockAddress)
        {
            int k = 0;
            for (int i = 0; i < _WordsPerBlock; i++)
            {
                for (int j = 0; j < _WordLength; j++)
                {
                    Memory[(BlockAddress * _WordsPerBlock) + i, j] = GivenBloc[k];
                    k++;
                }
            }

        }

        public void CLearBlock(int BlockAddress)
        {
            for (int i = 0; i < _WordsPerBlock; i++)
            {
                for (int j = 0; j < _WordLength; j++)
                {
                    Memory[(BlockAddress * _WordsPerBlock) + i, j] = '*';
                }
            }

        }

    }

    /*
    INPUT / OUTPUT
    */


    public class INputOutput
    {
        public char[] _Buffer;
        public int _WordLength { get; set; }
        public int _WordsPerBlock { get; set; }
        public readonly string CardReader = "C:\\Users\\arya2\\Documents\\OS_Coursse_Project\\OS_Phase_1\\IO_Files\\Input.txt";
        public readonly string LinePrinters = "C:\\Users\\arya2\\Documents\\OS_Coursse_Project\\OS_Phase_1\\IO_Files\\Output.txt";
        int LineNumber = 0;
        public INputOutput(int WordLength, int WordsPerBlock)
        {
            _Buffer = new char[WordsPerBlock * WordLength];
            _WordLength = WordLength;
            _WordsPerBlock = WordsPerBlock;

        }

        public void WriteTOBuffer(char[,] Data)
        {
            int k = 0;
            for (int i = 0; i < _WordsPerBlock; i++)
            {
                for (int j = 0; j < _WordLength; j++)
                {
                    _Buffer[k] = Data[i, j];
                    k++;
                }
            }
        }


        public void Write()
        {
            // StreamWriter sw = new StreamWriter(LinePrinters);
            String temp = "";
            for (int i = 0; i < _WordsPerBlock * _WordLength; i++)
            {
                temp += _Buffer[i];
            }
            // sw.Close();
            File.AppendAllText(LinePrinters, temp + Environment.NewLine);
        }

        public void Read()
        {
            StreamReader sr = new StreamReader(CardReader);

            String line = File.ReadLines(CardReader).Skip(LineNumber).Take(1).First();
            LineNumber++;


            _Buffer = line.ToCharArray();
            sr.Close();
        }
        public void ClearBuffer()
        {
            for (int i = 0; i < _Buffer.Length; i++)
            {
                _Buffer[i] = '*';
            }
        }

    }

    // CPU____________________________________

    public class CPU
    {
        public char[] _Register;
        public char[] _InstructionRegister;
        public char[] _ProgramCounter;
        public char[] _ToggleRegister;
        public int _SI; //interrupt


        public CPU(int RegisterSize, int InstructionSIze, int ProgramCOunterSize, int TOggleRegister)
        {
            _Register = new char[RegisterSize];
            _InstructionRegister = new char[InstructionSIze];
            _ProgramCounter = new char[ProgramCOunterSize];
            _ToggleRegister = new char[TOggleRegister];
            for (int i = 0; i < ProgramCOunterSize; i++)
            {
                _ProgramCounter[i] = '0';
            }


        }

        public void SetRegiset(char[] Register)
        {
            _Register = Register;
        }

        public char[] GetRegiset()
        {
            return _Register;
        }

        public void SetInstructionRegister(char[] InstructionRegister)

        {
            _InstructionRegister = InstructionRegister;
        }

        public char[] GetInctructionRegister()
        {

            return _InstructionRegister;
        }

        public void ClearInstructionRegister()
        {
            for (int i = 0; i < _InstructionRegister.Length; i++)
            {
                _InstructionRegister[i] = '\0';
            }
        }
        //hardcoded
        public int ParseIRNum()
        {
            return (_InstructionRegister[2] - '0') * 10 + (_InstructionRegister[3] - '0');
        }



    }


    //____________________OS_________________________
    public class OS
    {
        private readonly ExternalMemory _externalMemory;
        private readonly INputOutput _io;
        private readonly CPU _cpu;
        int stack_ptr = 0;
        int wrt_ptr = 0;
        public OS()
        {
            _externalMemory = new ExternalMemory(4, 10, 10);

            _io = new INputOutput(4, 10);
            _cpu = new CPU(4, 4, 2, 1);
            _cpu.SetInstructionRegister(new char[] { 'G', 'D', '0', '0' });
        }

        //hardcoded
        public void READ()
        {
            _io.ClearBuffer();
            //int MemoryLocation = _cpu.ParseIRNum();
            char[] MemoryLocation = _cpu.GetInctructionRegister();
            _io.Read();
            if (!(_io._Buffer[0] == '$' && _io._Buffer[1] == 'A' && _io._Buffer[2] == 'M' && _io._Buffer[3] == 'J'))
            {
                _externalMemory.SetBlock(_io._Buffer, stack_ptr);
                stack_ptr++;
            }
            else
            {
                Console.WriteLine("encountered $AMJ");
            }



            _io.ClearBuffer();


        }

        public void TERMINATE()
        {
            throw new NotImplementedException();
        }
        //again hardcded
        public void WRITE()
        {
            _io.ClearBuffer();
            char[] MemoryLocation = _cpu.GetInctructionRegister();
            //_io.WriteTOBuffer(_externalMemory.GetBlock(MemoryLocation[2] - '0'));
            _io.WriteTOBuffer(_externalMemory.GetBlock(wrt_ptr));
            wrt_ptr++;
            _io.Write();
            _io.ClearBuffer();
        }
        public void MOS()
        {
            if (_cpu._SI == 1)
            {
                READ();
            }
            if (_cpu._SI == 2)
            {
                WRITE();
            }
            if (_cpu._SI == 3)
            {
                TERMINATE();
            }
        }

        public void EXECUTE()
        {
            throw new NotImplementedException();
        }

        public void LOAD()
        {
            Console.WriteLine("Loadin'");



        }



    }

    internal class Progra
    {

        static void Mai(string[] args)
        {

            char[,] charMatrix = new char[,]
     {
            { 'A', 'B', 'C', 'D' },
            { 'E', 'F', 'G', 'H' },
            { 'I', 'J', 'K', 'L' },
            { 'M', 'N', 'O', 'P' },
            { 'Q', 'R', 'S', 'T' },
            { 'U', 'V', 'W', 'X' },
            { 'Y', 'Z', 'A', 'B' },
            { 'C', 'D', 'E', 'F' },
            { 'G', 'H', 'I', 'J' },
            { 'K', 'L', 'M', 'N' }
     };





            OS meowOS = new OS();
            meowOS.READ();
            meowOS.READ();
            meowOS.WRITE();
            meowOS.READ();
            meowOS.WRITE();
            Console.Write("dotnet mwoe");
        }
    }

}
